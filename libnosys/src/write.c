#include <errno.h>
#include <unistd.h>

#include "nosys.h"

ssize_t
_write(int fildes, const void *buf, size_t nbyte)
{
	if (fildes != STDOUT_FILENO && fildes != STDERR_FILENO) {
		errno = EBADF;
		return -1;
	}

	const char *begin = buf;
	const char *end = begin + nbyte;

	const char *bp = begin;
	while (bp < end) {
		size_t n = Chip_UART_SendRB(LPC_UART0, &__libnosys_txring, bp,
				end - bp);
		if (!n)
			break;
		bp += n;
	}

	if (nbyte && bp == begin) {
		errno = EAGAIN;
		return -1;
	}
	return bp - begin;
}
