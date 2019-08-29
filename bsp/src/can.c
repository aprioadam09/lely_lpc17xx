#include <chip.h>

#include <string.h>

#include <can.h>

#define CAN_ICR_TI	(CAN_ICR_TI1 | CAN_ICR_TI2 | CAN_ICR_TI3)
#define CAN_IER_TIE	(CAN_IER_TIE1 | CAN_IER_TIE2 | CAN_IER_TIE3)

#define CAN_RX_SIZE	16
#define CAN_TX_SIZE	16

static CAN_MSG_T rxbuff[CAN_RX_SIZE];
static CAN_MSG_T txbuff[CAN_TX_SIZE];

static RINGBUFF_T rxring;
static RINGBUFF_T txring;

static void can_flush(void);

void
can_init(int bitrate)
{
	RingBuffer_Init(&rxring, rxbuff, sizeof(CAN_MSG_T), CAN_RX_SIZE);
	RingBuffer_Init(&txring, txbuff, sizeof(CAN_MSG_T), CAN_TX_SIZE);

	// Pin configuration CAN1: select P0.21 as RD1 and P0.22 as TD1.
	Chip_IOCON_PinMux(LPC_IOCON, 0, 21, IOCON_MODE_PULLUP, IOCON_FUNC3);
	Chip_IOCON_PinMux(LPC_IOCON, 0, 22, IOCON_MODE_PULLUP, IOCON_FUNC3);
	Chip_IOCON_EnableOD(LPC_IOCON, 0, 21);
	Chip_IOCON_EnableOD(LPC_IOCON, 0, 22);

	Chip_CAN_Init(LPC_CAN1, LPC_CANAF, LPC_CANAF_RAM);
	Chip_CAN_SetBitRate(LPC_CAN1, bitrate);
	Chip_CAN_EnableInt(LPC_CAN1, CAN_IER_BITMASK);
	Chip_CAN_SetAFMode(LPC_CANAF, CAN_AF_BYBASS_MODE);

	NVIC_EnableIRQ(CAN_IRQn);
}

void
can_fini(void)
{
	NVIC_DisableIRQ(CAN_IRQn);
	Chip_CAN_DisableInt(LPC_CAN1, CAN_IER_BITMASK);
	Chip_CAN_DeInit(LPC_CAN1);
}

size_t
can_recv(struct can_msg *ptr, size_t n)
{
	size_t i = 0;
	for (; i < n; i++) {
		CAN_MSG_T Msg;
		if (!RingBuffer_Pop(&rxring, &Msg))
			break;

		// Convert the message to the LCI CAN frame format.
		ptr[i] = (struct can_msg)CAN_MSG_INIT;
		if (Msg.ID & CAN_EXTEND_ID_USAGE) {
			ptr[i].id = Msg.ID & CAN_MASK_EID;
			ptr[i].flags |= CAN_FLAG_IDE;
		} else {
			ptr[i].id = Msg.ID & CAN_MASK_BID;
		}
		if (Msg.Type == CAN_REMOTE_MSG)
			ptr[i].flags |= CAN_FLAG_RTR;
		ptr[i].len = MIN(Msg.DLC, CAN_MAX_LEN);
		memcpy(ptr[i].data, Msg.Data, ptr[i].len);
	}
	return i;
}

size_t
can_send(const struct can_msg *ptr, size_t n)
{
	size_t i = 0;
	// Disable transmit interrupts to prevent a race condition with
	// CAN_IRQHandler().
	Chip_CAN_DisableInt(LPC_CAN1, CAN_IER_TIE);
	for (; i < n; i++) {
		if (ptr[i].len > CAN_MAX_LEN)
			continue;

		// Convert the CAN frame to the LPC message format.
		CAN_MSG_T Msg;
		if (ptr[i].flags & CAN_FLAG_IDE) {
			Msg.ID = ptr[i].id & CAN_MASK_EID;
			Msg.ID |= CAN_EXTEND_ID_USAGE;
		} else {
			Msg.ID = ptr[i].id & CAN_MASK_BID;
		}
		Msg.Type = (ptr[i].flags & CAN_FLAG_RTR) ? CAN_REMOTE_MSG : 0;
		Msg.DLC = ptr[i].len;
		memcpy(Msg.Data, ptr[i].data, ptr[i].len);

		// Try to flush the buffer in a non-blocking way if it is full.
		if (RingBuffer_IsFull(&txring))
			can_flush();
		// Drop remaining messages if the buffer is full.
		if (!RingBuffer_Insert(&txring, &Msg))
			break;
	}
	// Try to send the messages we just added to the buffer.
	can_flush();
	// If any messages remain in the buffer, re-enable transmit interrupts
	// to let CAN_IRQHandler() handle them.
	if (!RingBuffer_IsEmpty(&txring))
		Chip_CAN_EnableInt(LPC_CAN1, CAN_IER_TIE);
	return i;
}

static void
can_flush(void)
{
	CAN_BUFFER_ID_T TxBufID;
	CAN_MSG_T Msg;
	while ((TxBufID = Chip_CAN_GetFreeTxBuf(LPC_CAN1)) != CAN_BUFFER_LAST
			&& RingBuffer_Pop(&txring, &Msg))
		Chip_CAN_Send(LPC_CAN1, TxBufID, &Msg);
}

void
CAN_IRQHandler(void)
{
	uint32_t IntStatus = Chip_CAN_GetIntStatus(LPC_CAN1);

	if (IntStatus & CAN_ICR_EI) {
		Chip_CAN_SetMode(LPC_CAN1, CAN_RESET_MODE, ENABLE);
		LPC_CAN1->GSR = 0;
		Chip_CAN_SetMode(LPC_CAN1, CAN_RESET_MODE, DISABLE);
	}

	if (IntStatus & CAN_ICR_TI) {
		// Flush the transmit buffer in a non-blocking way.
		can_flush();
		// Disable transmit interrupts if the buffer is empty.
		if (RingBuffer_IsEmpty(&txring))
			Chip_CAN_DisableInt(LPC_CAN1, CAN_IER_TIE);
	}

	if (IntStatus & CAN_ICR_RI) {
		CAN_MSG_T Msg;
		// Receive all pending messages. If the buffer is full we drop
		// them.
		while (Chip_CAN_Receive(LPC_CAN1, &Msg) == SUCCESS)
			RingBuffer_Insert(&rxring, &Msg);
	}
}
