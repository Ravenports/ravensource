#include <sys/types.h>
#include <sys/time.h>		/* XXX for mtree.h */
#include <sys/queue.h>

#include <err.h>
#include <fnmatch.h>
#include <fts.h>
#include <stdio.h>
#include <stdlib.h>

#include "mtree.h"		/* XXX for extern.h */
#include "extern.h"

/*
 * We're assuming that there won't be a whole lot of excludes, 
 * so it's OK to use a stupid algorithm.
 */
struct exclude {
	LIST_ENTRY(exclude) link;
	const char *glob;
	int pathname;
};
static LIST_HEAD(, exclude) excludes;

void
init_excludes(void)
{

	LIST_INIT(&excludes);
}

void
read_excludes_file(const char *name)
{
	FILE *fp;
	char *line, *str;
	struct exclude *e;
#ifdef __linux__
	size_t linecap = 0;
	ssize_t len;
#else
	size_t len;
#endif

	fp = fopen(name, "r");
	if (fp == NULL)
		err(1, "%s", name);

#ifdef __linux__
	while ((len = getline(&line, &linecap, fp)) != -1) {
#else
	while ((line = fgetln(fp, &len)) != NULL) {
#endif
		if (line[len - 1] == '\n')
			len--;
		if (len == 0)
			continue;

		str = malloc(len + 1);
		e = malloc(sizeof *e);
		if (str == NULL || e == NULL)
			errx(1, "memory allocation error");
		e->glob = str;
		memcpy(str, line, len);
		str[len] = '\0';
		if (strchr(str, '/'))
			e->pathname = 1;
		else
			e->pathname = 0;
		LIST_INSERT_HEAD(&excludes, e, link);
	}
#ifdef __linux__
	free(line);
#endif
	fclose(fp);
}

int
check_excludes(const char *fname, const char *path)
{
	struct exclude *e;

	/* fnmatch(3) has a funny return value convention... */
#define MATCH(g, n) (fnmatch((g), (n), FNM_PATHNAME) == 0)

	LIST_FOREACH(e, &excludes, link) {
		if ((e->pathname && MATCH(e->glob, path)) ||
		    MATCH(e->glob, fname))
			return 1;
	}
	return 0;
}
