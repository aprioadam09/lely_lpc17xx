#include <cmsis.h>

extern void __librt_init(void);
extern void __librt_fini(void);

extern void __libnosys_init(void);
extern void __libnosys_fini(void);

int
main(void)
{
	__librt_init();
	__libnosys_init();

	for (;;) {
		// Wait for an interrupt to occur.
		__WFI();
	}

	__libnosys_fini();
	__librt_fini();

	return 0;
}
