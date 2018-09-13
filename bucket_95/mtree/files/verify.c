#include <sys/param.h>
#include <sys/stat.h>
#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <fts.h>
#include <fnmatch.h>
#include <stdio.h>
#include <unistd.h>
#include "mtree.h"
#include "extern.h"

static NODE *root;
static char path[MAXPATHLEN];

static void	miss(NODE *, char *);
static int	vwalk(void);

int
verify(void)
{
	int rval;

	root = spec();
	rval = vwalk();
	miss(root, path);
	return (rval);
}

static int
vwalk(void)
{
	FTS *t;
	FTSENT *p;
	NODE *ep, *level;
	int specdepth, rval;
	char *argv[2], dot[] = ".";

	argv[0] = dot;
	argv[1] = NULL;
	if ((t = fts_open(argv, ftsoptions, NULL)) == NULL)
		err(1, "line %d: fts_open", lineno);
	level = root;
	specdepth = rval = 0;
	while ((p = fts_read(t))) {
		if (check_excludes(p->fts_name, p->fts_path)) {
			fts_set(t, p, FTS_SKIP);
			continue;
		}
		switch(p->fts_info) {
		case FTS_D:
		case FTS_SL:
			break;
		case FTS_DP:
			if (specdepth > p->fts_level) {
				for (level = level->parent; level->prev;
				      level = level->prev);
				--specdepth;
			}
			continue;
		case FTS_DNR:
		case FTS_ERR:
		case FTS_NS:
			warnx("%s: %s", RP(p), strerror(p->fts_errno));
			continue;
		default:
			if (dflag)
				continue;
		}

		if (specdepth != p->fts_level)
			goto extra;
		for (ep = level; ep; ep = ep->next)
			if ((ep->flags & F_MAGIC &&
			    !fnmatch(ep->name, p->fts_name, FNM_PATHNAME)) ||
			    !strcmp(ep->name, p->fts_name)) {
				ep->flags |= F_VISIT;
				if ((ep->flags & F_NOCHANGE) == 0 &&
				    compare(ep, p))
					rval = MISMATCHEXIT;
				if (ep->flags & F_IGN)
					fts_set(t, p, FTS_SKIP);
				else if (ep->child && ep->type == F_DIR &&
				    p->fts_info == FTS_D) {
					level = ep->child;
					++specdepth;
				}
				break;
			}

		if (ep)
			continue;
extra:
		if (!eflag) {
			printf("%s extra", RP(p));
			if (rflag) {
				if ((S_ISDIR(p->fts_statp->st_mode)
				    ? rmdir : unlink)(p->fts_accpath)) {
					printf(", not removed: %s",
					    strerror(errno));
				} else
					printf(", removed");
			}
			putchar('\n');
		}
		fts_set(t, p, FTS_SKIP);
	}
	fts_close(t);
	if (sflag)
		warnx("%s checksum: %u", fullpath, crc_total);
	return (rval);
}

static void
miss(NODE *p, char *tail)
{
	int create;
	char *tp;
	const char *type;

	for (; p; p = p->next) {
		if (p->type != F_DIR && (dflag || p->flags & F_VISIT))
			continue;
		strcpy(tail, p->name);
		if (!(p->flags & F_VISIT)) {
			/* Don't print missing message if file exists as a
			   symbolic link and the -q flag is set. */
			struct stat statbuf;
 
			if (qflag && stat(path, &statbuf) == 0)
				p->flags |= F_VISIT;
			else
				printf("%s missing", path);
		}
		if (p->type != F_DIR && p->type != F_LINK) {
			putchar('\n');
			continue;
		}

		create = 0;
		if (p->type == F_LINK)
			type = "symlink";
		else
			type = "directory";
		if (!(p->flags & F_VISIT) && uflag) {
			if (!(p->flags & (F_UID | F_UNAME)))
				printf(" (%s not created: user not specified)", type);
			else if (!(p->flags & (F_GID | F_GNAME)))
				printf(" (%s not created: group not specified)", type);
			else if (p->type == F_LINK) {
				if (symlink(p->slink, path))
					printf(" (symlink not created: %s)\n",
					    strerror(errno));
				else
					printf(" (created)\n");
				if (lchown(path, p->st_uid, p->st_gid))
					printf("%s: user/group not modified: %s\n",
					    path, strerror(errno));
				continue;
			} else if (!(p->flags & F_MODE))
			    printf(" (directory not created: mode not specified)");
			else if (mkdir(path, S_IRWXU))
				printf(" (directory not created: %s)",
				    strerror(errno));
			else {
				create = 1;
				printf(" (created)");
			}
		}
		if (!(p->flags & F_VISIT))
			putchar('\n');

		for (tp = tail; *tp; ++tp);
		*tp = '/';
		miss(p->child, tp + 1);
		*tp = '\0';

		if (!create)
			continue;
		if (chown(path, p->st_uid, p->st_gid)) {
			printf("%s: user/group/mode not modified: %s\n",
			    path, strerror(errno));
			printf("%s: warning: file mode %snot set\n", path,
			    (p->flags & F_FLAGS) ? "and file flags " : "");
			continue;
		}
		if (chmod(path, p->st_mode))
			printf("%s: permissions not set: %s\n",
			    path, strerror(errno));
#ifndef __sunlinux__
		if ((p->flags & F_FLAGS) && p->st_flags &&
		    chflags(path, p->st_flags))
			printf("%s: file flags not set: %s\n",
			    path, strerror(errno));
#endif /* __linux__ */
	}
}
