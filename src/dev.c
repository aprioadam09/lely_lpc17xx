#if !LELY_NO_MALLOC
#error Static object dictionaries are only supported when dynamic memory allocation is disabled.
#endif

#include <lely/co/detail/dev.h>
#include <lely/co/detail/obj.h>
#include <lely/util/cmp.h>

#define CO_DEV_STRING(s) NULL

static co_dev_t lpc17xx_dev = {
	.netid = 0,
	.id = 2,
	.tree = { .cmp = &uint16_cmp },
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING(""),
	.vendor_name = CO_DEV_STRING("Lely Industries N.V."),
#endif
	.vendor_id = 0x00000360,
#if !LELY_NO_CO_OBJ_NAME
	.product_name = CO_DEV_STRING(""),
#endif
	.product_code = 0x00000000,
	.revision = 0x00000000,
#if !LELY_NO_CO_OBJ_NAME
	.order_code = CO_DEV_STRING(""),
#endif
	.baud = 0 | CO_BAUD_125,
	.rate = 125,
	.lss = 0,
	.dummy = 0x000000FE
};

static struct {
	co_unsigned32_t sub0;
} lpc17xx_dev_1000_val = {
	.sub0 = 0x00000000,
};

static co_obj_t lpc17xx_dev_1000 = {
	.node = { .key = &lpc17xx_dev_1000.idx },
	.idx = 0x1000,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Device type"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1000_val,
	.size = sizeof(lpc17xx_dev_1000_val)
};

static co_sub_t lpc17xx_dev_1000sub0 = {
	.node = { .key = &lpc17xx_dev_1000sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Device type"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_1000_val.sub0,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned8_t sub0;
} lpc17xx_dev_1001_val = {
	.sub0 = 0x00,
};

static co_obj_t lpc17xx_dev_1001 = {
	.node = { .key = &lpc17xx_dev_1001.idx },
	.idx = 0x1001,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Error register"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1001_val,
	.size = sizeof(lpc17xx_dev_1001_val)
};

static co_sub_t lpc17xx_dev_1001sub0 = {
	.node = { .key = &lpc17xx_dev_1001sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED8,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Error register"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u8 = CO_UNSIGNED8_MIN },
	.max = { .u8 = CO_UNSIGNED8_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u8 = 0x00 },
#endif
	.val = &lpc17xx_dev_1001_val.sub0,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned32_t sub0;
} lpc17xx_dev_1012_val = {
	.sub0 = 0x80000100,
};

static co_obj_t lpc17xx_dev_1012 = {
	.node = { .key = &lpc17xx_dev_1012.idx },
	.idx = 0x1012,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("COB-ID time stamp object"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1012_val,
	.size = sizeof(lpc17xx_dev_1012_val)
};

static co_sub_t lpc17xx_dev_1012sub0 = {
	.node = { .key = &lpc17xx_dev_1012sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("COB-ID time stamp object"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x80000100 },
#endif
	.val = &lpc17xx_dev_1012_val.sub0,
	.access = CO_ACCESS_RW,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned16_t sub0;
} lpc17xx_dev_1017_val = {
	.sub0 = 0x0032,
};

static co_obj_t lpc17xx_dev_1017 = {
	.node = { .key = &lpc17xx_dev_1017.idx },
	.idx = 0x1017,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Producer heartbeat time"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1017_val,
	.size = sizeof(lpc17xx_dev_1017_val)
};

static co_sub_t lpc17xx_dev_1017sub0 = {
	.node = { .key = &lpc17xx_dev_1017sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED16,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Producer heartbeat time"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u16 = CO_UNSIGNED16_MIN },
	.max = { .u16 = CO_UNSIGNED16_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u16 = 0x0032 },
#endif
	.val = &lpc17xx_dev_1017_val.sub0,
	.access = CO_ACCESS_RW,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned8_t sub0;
	co_unsigned32_t sub1;
	co_unsigned32_t sub2;
	co_unsigned32_t sub3;
	co_unsigned32_t sub4;
} lpc17xx_dev_1018_val = {
	.sub0 = 0x04,
	.sub1 = 0x00000360,
	.sub2 = 0x00000000,
	.sub3 = 0x00000000,
	.sub4 = 0x00000000,
};

static co_obj_t lpc17xx_dev_1018 = {
	.node = { .key = &lpc17xx_dev_1018.idx },
	.idx = 0x1018,
	.code = CO_OBJECT_RECORD,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Identity object"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1018_val,
	.size = sizeof(lpc17xx_dev_1018_val)
};

static co_sub_t lpc17xx_dev_1018sub0 = {
	.node = { .key = &lpc17xx_dev_1018sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED8,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Highest sub-index supported"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u8 = CO_UNSIGNED8_MIN },
	.max = { .u8 = CO_UNSIGNED8_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u8 = 0x04 },
#endif
	.val = &lpc17xx_dev_1018_val.sub0,
	.access = CO_ACCESS_CONST,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static co_sub_t lpc17xx_dev_1018sub1 = {
	.node = { .key = &lpc17xx_dev_1018sub1.subidx },
	.subidx = 0x01,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Vendor-ID"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000360 },
#endif
	.val = &lpc17xx_dev_1018_val.sub1,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static co_sub_t lpc17xx_dev_1018sub2 = {
	.node = { .key = &lpc17xx_dev_1018sub2.subidx },
	.subidx = 0x02,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Product code"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_1018_val.sub2,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static co_sub_t lpc17xx_dev_1018sub3 = {
	.node = { .key = &lpc17xx_dev_1018sub3.subidx },
	.subidx = 0x03,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Revision number"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_1018_val.sub3,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static co_sub_t lpc17xx_dev_1018sub4 = {
	.node = { .key = &lpc17xx_dev_1018sub4.subidx },
	.subidx = 0x04,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Serial number"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_1018_val.sub4,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned32_t sub0;
} lpc17xx_dev_1F80_val = {
	.sub0 = 0x00000004,
};

static co_obj_t lpc17xx_dev_1F80 = {
	.node = { .key = &lpc17xx_dev_1F80.idx },
	.idx = 0x1F80,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("NMT startup"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_1F80_val,
	.size = sizeof(lpc17xx_dev_1F80_val)
};

static co_sub_t lpc17xx_dev_1F80sub0 = {
	.node = { .key = &lpc17xx_dev_1F80sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("NMT startup"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_1F80_val.sub0,
	.access = CO_ACCESS_RW,
	.pdo_mapping = 0,
	.flags = 0 | CO_OBJ_FLAGS_PARAMETER_VALUE,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned32_t sub0;
} lpc17xx_dev_2000_val = {
	.sub0 = 0x00000000,
};

static co_obj_t lpc17xx_dev_2000 = {
	.node = { .key = &lpc17xx_dev_2000.idx },
	.idx = 0x2000,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Object with custom SDO download callback"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_2000_val,
	.size = sizeof(lpc17xx_dev_2000_val)
};

static co_sub_t lpc17xx_dev_2000sub0 = {
	.node = { .key = &lpc17xx_dev_2000sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Object with custom SDO download callback"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_2000_val.sub0,
	.access = CO_ACCESS_RW,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

static struct {
	co_unsigned32_t sub0;
} lpc17xx_dev_2001_val = {
	.sub0 = 0x00000000,
};

static co_obj_t lpc17xx_dev_2001 = {
	.node = { .key = &lpc17xx_dev_2001.idx },
	.idx = 0x2001,
	.code = CO_OBJECT_VAR,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Object with custom SDO upload callback"),
#endif
	.tree = { .cmp = &uint8_cmp },
	.val = &lpc17xx_dev_2001_val,
	.size = sizeof(lpc17xx_dev_2001_val)
};

static co_sub_t lpc17xx_dev_2001sub0 = {
	.node = { .key = &lpc17xx_dev_2001sub0.subidx },
	.subidx = 0x00,
	.type = CO_DEFTYPE_UNSIGNED32,
#if !LELY_NO_CO_OBJ_NAME
	.name = CO_DEV_STRING("Object with custom SDO upload callback"),
#endif
#if !LELY_NO_CO_OBJ_LIMITS
	.min = { .u32 = CO_UNSIGNED32_MIN },
	.max = { .u32 = CO_UNSIGNED32_MAX },
#endif
#if !LELY_NO_CO_OBJ_DEFAULT
	.def = { .u32 = 0x00000000 },
#endif
	.val = &lpc17xx_dev_2001_val.sub0,
	.access = CO_ACCESS_RO,
	.pdo_mapping = 0,
	.flags = 0,
	.dn_ind = &co_sub_default_dn_ind,
#if !LELY_NO_CO_OBJ_UPLOAD
	.up_ind = &co_sub_default_up_ind
#endif
};

// suppress missing-prototype warning
co_dev_t * lpc17xx_dev_init(void);
co_dev_t *
lpc17xx_dev_init(void) {
	static co_dev_t *dev = NULL;
	if (!dev) {
		dev = &lpc17xx_dev;

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1000);
		co_obj_insert_sub(&lpc17xx_dev_1000, &lpc17xx_dev_1000sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1001);
		co_obj_insert_sub(&lpc17xx_dev_1001, &lpc17xx_dev_1001sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1012);
		co_obj_insert_sub(&lpc17xx_dev_1012, &lpc17xx_dev_1012sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1017);
		co_obj_insert_sub(&lpc17xx_dev_1017, &lpc17xx_dev_1017sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1018);
		co_obj_insert_sub(&lpc17xx_dev_1018, &lpc17xx_dev_1018sub0);
		co_obj_insert_sub(&lpc17xx_dev_1018, &lpc17xx_dev_1018sub1);
		co_obj_insert_sub(&lpc17xx_dev_1018, &lpc17xx_dev_1018sub2);
		co_obj_insert_sub(&lpc17xx_dev_1018, &lpc17xx_dev_1018sub3);
		co_obj_insert_sub(&lpc17xx_dev_1018, &lpc17xx_dev_1018sub4);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_1F80);
		co_obj_insert_sub(&lpc17xx_dev_1F80, &lpc17xx_dev_1F80sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_2000);
		co_obj_insert_sub(&lpc17xx_dev_2000, &lpc17xx_dev_2000sub0);

		co_dev_insert_obj(&lpc17xx_dev, &lpc17xx_dev_2001);
		co_obj_insert_sub(&lpc17xx_dev_2001, &lpc17xx_dev_2001sub0);
	}
	return dev;
}
