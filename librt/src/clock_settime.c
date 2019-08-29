#include <chip.h>

#include <errno.h>

#include "rt.h"

int
clock_settime(clockid_t clock_id, const struct timespec *tp)
{
	if (clock_id != CLOCK_REALTIME || tp->tv_nsec < 0
			|| tp->tv_nsec > 1000000000l) {
		errno = EINVAL;
		return -1;
	}

	uint32_t priMask = __get_PRIMASK();
	__disable_irq();

	__librt_realtime.tv_sec = tp->tv_sec - __librt_monotonic.tv_sec;
	__librt_realtime.tv_nsec = tp->tv_nsec - __librt_monotonic.tv_nsec;
	if (__librt_realtime.tv_nsec < 0) {
		__librt_realtime.tv_sec--;
		__librt_realtime.tv_nsec += 1000000000l;
	} else if (__librt_realtime.tv_nsec >= 1000000000l) {
		__librt_realtime.tv_sec++;
		__librt_realtime.tv_nsec -= 1000000000l;
	}

	__set_PRIMASK(priMask);

	return 0;
}
