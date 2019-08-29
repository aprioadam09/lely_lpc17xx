#include <chip.h>

#include "rt.h"

struct timespec __librt_monotonic;
struct timespec __librt_realtime;

void
__librt_init(void)
{
	// Read clock settings and update SystemCoreClock variable.
	SystemCoreClockUpdate();
	// Enable and setup SysTick Timer at a periodic rate.
	SysTick_Config(SystemCoreClock / CLOCKS_PER_SEC);
}

void
__librt_fini(void)
{
}

void
SysTick_Handler(void)
{
	struct timespec res;
	clock_getres(CLOCK_MONOTONIC, &res);

	uint32_t priMask = __get_PRIMASK();
	__disable_irq();

	__librt_monotonic.tv_sec += res.tv_sec;
	__librt_monotonic.tv_nsec += res.tv_nsec;
	if (__librt_monotonic.tv_nsec > 1000000000l) {
		__librt_monotonic.tv_sec++;
		__librt_monotonic.tv_nsec -= 1000000000l;
	}

	__set_PRIMASK(priMask);
}
