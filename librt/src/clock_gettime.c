#include <chip.h>

#include <errno.h>

#include "rt.h"

int
clock_gettime(clockid_t clock_id, struct timespec *tp)
{
	if (clock_id != CLOCK_REALTIME && clock_id != CLOCK_MONOTONIC) {
		errno = EINVAL;
		return -1;
	}

	uint32_t priMask = __get_PRIMASK();
	__disable_irq();

	*tp = __librt_monotonic;
	if (clock_id == CLOCK_REALTIME) {
		tp->tv_sec += __librt_realtime.tv_sec;
		tp->tv_nsec += __librt_realtime.tv_nsec;
		if (tp->tv_nsec < 0) {
			tp->tv_sec--;
			tp->tv_nsec += 1000000000l;
		} else if (tp->tv_nsec >= 1000000000l) {
			tp->tv_sec++;
			tp->tv_nsec -= 1000000000l;
		}
	}

	__set_PRIMASK(priMask);

	return 0;
}
