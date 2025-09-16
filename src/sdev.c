#include <lely/co/sdev.h>

#define CO_SDEV_STRING(s)	NULL

const struct co_sdev lpc17xx_sdev = {
	.id = 0x02,
	.name = NULL,
	.vendor_name = CO_SDEV_STRING("Lely Industries N.V."),
	.vendor_id = 0x00000360,
	.product_name = NULL,
	.product_code = 0x00000000,
	.revision = 0x00000000,
	.order_code = NULL,
	.baud = 0
		| CO_BAUD_125,
	.rate = 0,
	.lss = 0,
	.dummy = 0x000000fe,
	.nobj = 12,
	.objs = (const struct co_sobj[]){{
		.name = CO_SDEV_STRING("Device type"),
		.idx = 0x1000,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Device type"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Error register"),
		.idx = 0x1001,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Error register"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED8,
			.min = { .u8 = CO_UNSIGNED8_MIN },
			.max = { .u8 = CO_UNSIGNED8_MAX },
			.def = { .u8 = CO_UNSIGNED8_MIN },
			.val = { .u8 = CO_UNSIGNED8_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("COB-ID time stamp object"),
		.idx = 0x1012,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("COB-ID time stamp object"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = 0x80000100lu },
			.val = { .u32 = 0x80000100lu },
			.access = CO_ACCESS_RW,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Producer heartbeat time"),
		.idx = 0x1017,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Producer heartbeat time"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED16,
			.min = { .u16 = CO_UNSIGNED16_MIN },
			.max = { .u16 = CO_UNSIGNED16_MAX },
			.def = { .u16 = 0x0000u },
			.val = { .u16 = 0x0000u },
			.access = CO_ACCESS_RW,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Identity object"),
		.idx = 0x1018,
		.code = CO_OBJECT_RECORD,
		.nsub = 5,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Highest sub-index supported"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED8,
			.min = { .u8 = CO_UNSIGNED8_MIN },
			.max = { .u8 = CO_UNSIGNED8_MAX },
			.def = { .u8 = 0x04 },
			.val = { .u8 = 0x04 },
			.access = CO_ACCESS_CONST,
			.pdo_mapping = 0,
			.flags = 0
		}, {
			.name = CO_SDEV_STRING("Vendor-ID"),
			.subidx = 0x01,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = 0x00000360lu },
			.val = { .u32 = 0x00000360lu },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}, {
			.name = CO_SDEV_STRING("Product code"),
			.subidx = 0x02,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}, {
			.name = CO_SDEV_STRING("Revision number"),
			.subidx = 0x03,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}, {
			.name = CO_SDEV_STRING("Serial number"),
			.subidx = 0x04,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("NMT startup"),
		.idx = 0x1f80,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("NMT startup"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = 0x00000004lu },
			.access = CO_ACCESS_RW,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Object with custom SDO download callback"),
		.idx = 0x2000,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Object with custom SDO download callback"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RW,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Object with custom SDO upload callback"),
		.idx = 0x2001,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Object with custom SDO upload callback"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED32,
			.min = { .u32 = CO_UNSIGNED32_MIN },
			.max = { .u32 = CO_UNSIGNED32_MAX },
			.def = { .u32 = CO_UNSIGNED32_MIN },
			.val = { .u32 = CO_UNSIGNED32_MIN },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("LED Object with custom SDO upload callback"),
		.idx = 0x2100,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("LED Object with custom SDO upload callback"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED8,
			.min = { .u8 = 0 },
			.max = { .u8 = 3 },
			.def = { .u8 = 0 },
			.val = { .u8 = 0 },
			.access = CO_ACCESS_RW,
			.pdo_mapping = 0,
			.flags = 0
		}}
	}, {
		.name = CO_SDEV_STRING("Button Object with custom SDO upload callback"),
		.idx = 0x2110,
		.code = CO_OBJECT_VAR,
		.nsub = 1,
		.subs = (const struct co_ssub[]){{
			.name = CO_SDEV_STRING("Button Object with custom SDO upload callback"),
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED8,
			.min = { .u8 = 0 },
			.max = { .u8 = 1 },
			.def = { .u8 = 0 },
			.val = { .u8 = 0 },
			.access = CO_ACCESS_RO,
			.pdo_mapping = 1,
			.flags = 0
		}}
	}, { // TPDO 1 Communication Parameter - Correct Syntax
		.idx = 0x1800,
		.code = CO_OBJECT_RECORD,
		.nsub = 6, // Kita definisikan sub-objek yang paling umum
		.subs = (const struct co_ssub[]){{
			.subidx = 0x00,
			.type = CO_DEFTYPE_UNSIGNED8,
			.val = { .u8 = 5 }, // Jumlah sub-objek yang aktif
			.access = CO_ACCESS_RO
		}, {
			.subidx = 0x01, // COB-ID
			.type = CO_DEFTYPE_UNSIGNED32,
			.val = { .u32 = 0x00000180 | 2 }, // Default COB-ID = 0x180 + Node ID 2
			.access = CO_ACCESS_RW
		}, {
			.subidx = 0x02, // Transmission Type
			.type = CO_DEFTYPE_UNSIGNED8,
			.val = { .u8 = 254 }, // 254 = event-driven (asynchronous)
			.access = CO_ACCESS_RW
		}, {
			.subidx = 0x03, // Inhibit Time
			.type = CO_DEFTYPE_UNSIGNED16,
			.val = { .u16 = 0 },
			.access = CO_ACCESS_RW
		}, {
			.subidx = 0x05, // Event Timer
			.type = CO_DEFTYPE_UNSIGNED16,
			.val = { .u16 = 0 }, // 100 ms change to 0 for purely event-driven TPDO
			.access = CO_ACCESS_RW
		}, {
			.subidx = 0x06, // SYNC start value
			.type = CO_DEFTYPE_UNSIGNED8,
			.val = { .u8 = 0 },
			.access = CO_ACCESS_RW
		}}
	}, { // TPDO 1 Mapping Parameter - Correct Syntax
		.idx = 0x1A00,
		.code = CO_OBJECT_RECORD,
		.nsub = 2,
		.subs = (const struct co_ssub[]){{
			.subidx = 0x00, // Number of mapped objects
			.type = CO_DEFTYPE_UNSIGNED8,
			.val = { .u8 = 1 },
			.access = CO_ACCESS_RW
		}, {
			.subidx = 0x01, // 1st mapped object
			.type = CO_DEFTYPE_UNSIGNED32,
			.val = { .u32 = 0x21100008 }, // Map: Obj 0x2110, Sub 0, 8 bits
			.access = CO_ACCESS_RW
		}}
	}}
};

