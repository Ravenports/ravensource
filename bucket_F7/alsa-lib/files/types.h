#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <sys/types.h>

#define __bitwise
#define __u8 u_int8_t

typedef pid_t __kernel_pid_t;
typedef off_t __kernel_off_t;

typedef uint64_t __u64;
#endif /* _LINUX_TYPES_H */
