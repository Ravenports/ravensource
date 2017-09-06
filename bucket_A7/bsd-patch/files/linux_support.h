#ifndef LINUX_SUPPORT_H
#define LINUX_SUPPORT_H

#ifdef __linux__
#include <bsd/stdio.h>
#include <bsd/stdlib.h>
#include <bsd/unistd.h>
#include <bsd/string.h>

#define asprintf	bsd_asprintf

int	bsd_asprintf(char **strp, const char *fmt, ...);

#endif

#endif /* LINUX_SUPPORT_H */
