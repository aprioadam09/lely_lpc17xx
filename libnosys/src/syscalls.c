#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

#undef errno
extern int errno;

void _exit(int status) {
    (void)status;
    while (1) {}
}

int _close(int file) {
    (void)file;
    return -1;
}

int _execve(char *name, char **argv, char **env) {
    (void)name;
    (void)argv;
    (void)env;
    errno = ENOMEM;
    return -1;
}

int _fork(void) {
    errno = EAGAIN;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _getpid(void) {
    return 1;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _kill(int pid, int sig) {
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

int _link(char *old, char *new) {
    (void)old;
    (void)new;
    errno = EMLINK;
    return -1;
}

int _lseek(int file, int ptr, int dir) {
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

int _open(const char *name, int flags, int mode) {
    (void)name;
    (void)flags;
    (void)mode;
    return -1;
}

int _read(int file, char *ptr, int len) {
    (void)file;
    (void)ptr;
    (void)len;
    return 0;
}

caddr_t _sbrk(int incr) {
    extern char end; /* Didefinisikan oleh linker */
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &end;
    }
    prev_heap_end = heap_end;

    // Cek batas heap jika didefinisikan oleh linker
    extern char _pvHeapLimit;
    if (heap_end + incr > &_pvHeapLimit) {
        errno = ENOMEM;
        return (caddr_t)-1;
    }

    heap_end += incr;
    return (caddr_t)prev_heap_end;
}

int _stat(const char *file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

clock_t _times(struct tms *buf) {
    (void)buf;
    return -1;
}

int _unlink(char *name) {
    (void)name;
    errno = ENOENT;
    return -1;
}

int _wait(int *status) {
    (void)status;
    errno = ECHILD;
    return -1;
}

int _write(int file, char *ptr, int len) {
    (void)file;
    (void)ptr;
    (void)len;
    return len;
}

int _gettimeofday(struct timeval *tv, void *tz) {
    (void)tz;
    if (tv) {
        tv->tv_sec = 0;
        tv->tv_usec = 0;
    }
    return 0;
}
