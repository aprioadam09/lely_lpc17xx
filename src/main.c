#include <cmsis.h>

#include <lely/can/net.h>

#include <assert.h>
#include <time.h>

#include <can.h>

extern void __librt_init(void);
extern void __librt_fini(void);

extern void __libnosys_init(void);
extern void __libnosys_fini(void);

#ifndef CAN_BITRATE
#define CAN_BITRATE 125000
#endif

static int on_can_send(const struct can_msg *msg, void *data);

int
main(void)
{
	__librt_init();
	__libnosys_init();

	can_init(CAN_BITRATE);

	// Initialize the CAN network interface.
	can_net_t *net = can_net_create();
	assert(net);
	can_net_set_send_func(net, &on_can_send, NULL);

	// Initialize the CAN network clock. We use the monotonic clock, since
	// its reference will not be changed by clock_settime().
	struct timespec now = { 0, 0 };
	clock_gettime(CLOCK_MONOTONIC, &now);
	can_net_set_time(net, &now);

	for (;;) {
		// Update the CAN network clock.
		clock_gettime(CLOCK_MONOTONIC, &now);
		can_net_set_time(net, &now);

		// Process any received CAN frames.
		struct can_msg msg;
		while (can_recv(&msg, 1))
			can_net_recv(net, &msg);

		// Wait for an interrupt to occur.
		__WFI();
	}

	can_net_destroy(net);

	can_fini();

	__libnosys_fini();
	__librt_fini();

	return 0;
}

static int
on_can_send(const struct can_msg *msg, void *data)
{
	(void)data;

	return can_send(msg, 1) == 1 ? 0 : -1;
}
