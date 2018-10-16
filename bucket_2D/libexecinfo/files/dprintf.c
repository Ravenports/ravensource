#include <stdio.h>
#include <unistd.h>

int
dprintf(int fd, const char *fmt, ...)
{
	FILE *fp;
	int e;
	__builtin_va_list ap;

	if ((e = dup(fd)) == -1)
		return -1;

	if ((fp = fdopen(e, "r+")) == NULL) {
		(void)close(e);
		return -1;
	}

	__builtin_va_start(ap, fmt);
	e = vfprintf(fp, fmt, ap);
	__builtin_va_end(ap);

	(void)fclose(fp);
	return e;
}
