#ifndef LIBBSD_ERR_H
#define LIBBSD_ERR_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define err(exitcode, format, args...) \
        errx(exitcode, format ": %s", ## args, strerror(errno))
#define errx(exitcode, format, args...) \
        { warnx(format, ## args); exit(exitcode); }
#define warn(format, args...) \
        warnx(format ": %s", ## args, strerror(errno))
#define warnx(format, args...) \
        fprintf(stderr, format "\n", ## args)

// more sun fixes

#include <limits.h>
#define u_int64_t	uint64_t

#endif
