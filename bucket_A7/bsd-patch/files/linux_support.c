#ifndef LINUX_SUPPORT_C
#define LINUX_SUPPORT_C

#ifdef __linux__
#include <stdarg.h>
#include "linux_support.h"

static int
bsd_vasprintf(char **strp, const char *fmt, va_list args)
{
    va_list args_copy;
    int status, needed;

    va_copy(args_copy, args);
    needed = vsnprintf(NULL, 0, fmt, args_copy);
    va_end(args_copy);
    if (needed < 0) {
        *strp = NULL;
        return needed;
    }
    *strp = malloc(needed + 1);
    if (*strp == NULL)
        return -1;
    status = vsnprintf(*strp, needed + 1, fmt, args);
    if (status >= 0)
        return status;
    else {
        free(*strp);
        *strp = NULL;
        return status;
    }
}

int
bsd_asprintf(char **strp, const char *fmt, ...)
{
    va_list args;
    int status;

    va_start(args, fmt);
    status = bsd_vasprintf(strp, fmt, args);
    va_end(args);
    return status;
}
#endif /* __Linux__ */

#endif /* LINUX_SUPPORT_C */
