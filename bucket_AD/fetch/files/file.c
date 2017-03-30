#include <sys/cdefs.h>

#include <sys/param.h>
#include <sys/stat.h>

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "fetch.h"
#include "common.h"

FILE *
fetchXGetFile(struct url *u, struct url_stat *us, const char *flags)
{
	FILE *f;

	if (us && fetchStatFile(u, us, flags) == -1)
		return (NULL);

	f = fopen(u->doc, "re");

	if (f == NULL) {
		fetch_syserr();
		return (NULL);
	}

	if (u->offset && fseeko(f, u->offset, SEEK_SET) == -1) {
		fclose(f);
		fetch_syserr();
		return (NULL);
	}

	return (f);
}

FILE *
fetchGetFile(struct url *u, const char *flags)
{
	return (fetchXGetFile(u, NULL, flags));
}

FILE *
fetchPutFile(struct url *u, const char *flags)
{
	FILE *f;

	if (CHECK_FLAG('a'))
		f = fopen(u->doc, "ae");
	else
		f = fopen(u->doc, "w+e");

	if (f == NULL) {
		fetch_syserr();
		return (NULL);
	}

	if (u->offset && fseeko(f, u->offset, SEEK_SET) == -1) {
		fclose(f);
		fetch_syserr();
		return (NULL);
	}

	return (f);
}

static int
fetch_stat_file(const char *fn, struct url_stat *us)
{
	struct stat sb;

	us->size = -1;
	us->atime = us->mtime = 0;
	if (stat(fn, &sb) == -1) {
		fetch_syserr();
		return (-1);
	}
	us->size = sb.st_size;
	us->atime = sb.st_atime;
	us->mtime = sb.st_mtime;
	return (0);
}

int
fetchStatFile(struct url *u, struct url_stat *us, const char *flags __unused)
{
	return (fetch_stat_file(u->doc, us));
}

struct url_ent *
fetchListFile(struct url *u, const char *flags __unused)
{
	struct dirent *de;
	struct url_stat us;
	struct url_ent *ue;
	int size, len;
	char fn[PATH_MAX], *p;
	DIR *dir;
	int l;

	if ((dir = opendir(u->doc)) == NULL) {
		fetch_syserr();
		return (NULL);
	}

	ue = NULL;
	strncpy(fn, u->doc, sizeof(fn) - 2);
	fn[sizeof(fn) - 2] = 0;
	strcat(fn, "/");
	p = strchr(fn, 0);
	l = sizeof(fn) - strlen(fn) - 1;

	while ((de = readdir(dir)) != NULL) {
		strncpy(p, de->d_name, l - 1);
		p[l - 1] = 0;
		if (fetch_stat_file(fn, &us) == -1)
			/* should I return a partial result, or abort? */
			break;
		fetch_add_entry(&ue, &size, &len, de->d_name, &us);
	}

	return (ue);
}
