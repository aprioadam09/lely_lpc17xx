#include <chip.h>

#include <errno.h>

#include "rt.h"

int
clock_getres(clockid_t clock_id, struct timespec *tp)
{
	if (clock_id != CLOCK_REALTIME && clock_id != CLOCK_MONOTONIC) {
		errno = EINVAL;
		return -1;
	}

	uint32_t tick = SysTick->LOAD + 1;
	uint32_t freq = SystemCoreClock;
	*tp = (struct timespec){
		tick / freq,
		((long)(tick % freq) / (freq / 1000000)) * 1000
	};

	return 0;
}
