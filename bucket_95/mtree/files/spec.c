#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fts.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <vis.h>
#include "mtree.h"
#include "extern.h"

int lineno;				/* Current spec line number. */

static void	 set(char *, NODE *);
static void	 unset(char *, NODE *);

NODE *
spec(void)
{
	NODE *centry, *last;
	char *p;
	NODE ginfo, *root;
	int c_cur, c_next;
	char buf[2048];

	centry = last = root = NULL;
	bzero(&ginfo, sizeof(ginfo));
	c_cur = c_next = 0;
	for (lineno = 1; fgets(buf, sizeof(buf), stdin);
	    ++lineno, c_cur = c_next, c_next = 0) {
		/* Skip empty lines. */
		if (buf[0] == '\n')
			continue;

		/* Find end of line. */
		if ((p = strchr(buf, '\n')) == NULL)
			errx(1, "line %d too long", lineno);

		/* See if next line is continuation line. */
		if (p[-1] == '\\') {
			--p;
			c_next = 1;
		}

		/* Null-terminate the line. */
		*p = '\0';

		/* Skip leading whitespace. */
		for (p = buf; *p && isspace(*p); ++p);

		/* If nothing but whitespace or comment char, continue. */
		if (!*p || *p == '#')
			continue;

#ifdef DEBUG
		fprintf(stderr, "line %d: {%s}\n", lineno, p);
#endif
		if (c_cur) {
			set(p, centry);
			continue;
		}

		/* Grab file name, "$", "set", or "unset". */
		if ((p = strtok(p, "\n\t ")) == NULL)
			errx(1, "line %d: missing field", lineno);

		if (p[0] == '/')
			switch(p[1]) {
			case 's':
				if (strcmp(p + 1, "set"))
					break;
				set(NULL, &ginfo);
				continue;
			case 'u':
				if (strcmp(p + 1, "unset"))
					break;
				unset(NULL, &ginfo);
				continue;
			}

		if (strchr(p, '/'))
			errx(1, "line %d: slash character in file name",
			lineno);

		if (!strcmp(p, "..")) {
			/* Don't go up, if haven't gone down. */
			if (!root)
				goto noparent;
			if (last->type != F_DIR || last->flags & F_DONE) {
				if (last == root)
					goto noparent;
				last = last->parent;
			}
			last->flags |= F_DONE;
			continue;

noparent:		errx(1, "line %d: no parent node", lineno);
		}

		if ((centry = calloc(1, sizeof(NODE) + strlen(p))) == NULL)
			errx(1, "calloc");
		*centry = ginfo;
#define	MAGIC	"?*["
		if (strpbrk(p, MAGIC))
			centry->flags |= F_MAGIC;
		if (strunvis(centry->name, p) == -1) {
			warnx("filename %s is ill-encoded and literally used",
			    p);
			strcpy(centry->name, p);
		}
		set(NULL, centry);

		if (!root) {
			last = root = centry;
			root->parent = root;
		} else if (last->type == F_DIR && !(last->flags & F_DONE)) {
			centry->parent = last;
			last = last->child = centry;
		} else {
			centry->parent = last->parent;
			centry->prev = last;
			last = last->next = centry;
		}
	}
	return (root);
}

static void
set(char *t, NODE *ip)
{
	int type;
	char *kw, *val = NULL;
	struct group *gr;
	struct passwd *pw;
	mode_t *m;
	int value;
	char *ep;

	for (; (kw = strtok(t, "= \t\n")); t = NULL) {
		ip->flags |= type = parsekey(kw, &value);
		if (value && (val = strtok(NULL, " \t\n")) == NULL)
			errx(1, "line %d: missing value", lineno);
		switch(type) {
		case F_CKSUM:
			ip->cksum = strtoul(val, &ep, 10);
			if (*ep)
				errx(1, "line %d: invalid checksum %s",
				lineno, val);
			break;
		case F_MD5:
			ip->md5digest = strdup(val);
			if(!ip->md5digest) {
				errx(1, "strdup");
			}
			break;
		case F_SHA1:
			ip->sha1digest = strdup(val);
			if(!ip->sha1digest) {
				errx(1, "strdup");
			}
			break;
		case F_RMD160:
			ip->rmd160digest = strdup(val);
			if(!ip->rmd160digest) {
				errx(1, "strdup");
			}
			break;
#ifndef __sunlinux__
		case F_FLAGS:
			if (strcmp("none", val) == 0)
				ip->st_flags = 0;
			else if (strtofflags(&val, &ip->st_flags, NULL) != 0)
				errx(1, "line %d: invalid flag %s",lineno, val);
 			break;
#endif /* __sunlinux__ */
		case F_GID:
			ip->st_gid = strtoul(val, &ep, 10);
			if (*ep)
				errx(1, "line %d: invalid gid %s", lineno, val);
			break;
		case F_GNAME:
			if ((gr = getgrnam(val)) == NULL)
			    errx(1, "line %d: unknown group %s", lineno, val);
			ip->st_gid = gr->gr_gid;
			break;
		case F_IGN:
			/* just set flag bit */
			break;
		case F_MODE:
			if ((m = setmode(val)) == NULL)
				errx(1, "line %d: invalid file mode %s",
				lineno, val);
			ip->st_mode = getmode(m, 0);
			free(m);
			break;
		case F_NLINK:
			ip->st_nlink = strtoul(val, &ep, 10);
			if (*ep)
				errx(1, "line %d: invalid link count %s",
				lineno,  val);
			break;
		case F_SIZE:
#ifdef __sun__
			ip->st_size = strtoll(val, &ep, 10);
#else
			ip->st_size = strtoq(val, &ep, 10);
#endif
			if (*ep)
				errx(1, "line %d: invalid size %s",
				lineno, val);
			break;
		case F_SLINK:
			if ((ip->slink = strdup(val)) == NULL)
				errx(1, "strdup");
			break;
		case F_TIME:
			ip->st_mtimespec.tv_sec = strtoul(val, &ep, 10);
			if (*ep != '.')
				errx(1, "line %d: invalid time %s",
				lineno, val);
			val = ep + 1;
			ip->st_mtimespec.tv_nsec = strtoul(val, &ep, 10);
			if (*ep)
				errx(1, "line %d: invalid time %s",
				lineno, val);
			break;
		case F_TYPE:
			switch(*val) {
			case 'b':
				if (!strcmp(val, "block"))
					ip->type = F_BLOCK;
				break;
			case 'c':
				if (!strcmp(val, "char"))
					ip->type = F_CHAR;
				break;
			case 'd':
				if (!strcmp(val, "dir"))
					ip->type = F_DIR;
				break;
			case 'f':
				if (!strcmp(val, "file"))
					ip->type = F_FILE;
				if (!strcmp(val, "fifo"))
					ip->type = F_FIFO;
				break;
			case 'l':
				if (!strcmp(val, "link"))
					ip->type = F_LINK;
				break;
			case 's':
				if (!strcmp(val, "socket"))
					ip->type = F_SOCK;
				break;
			default:
				errx(1, "line %d: unknown file type %s",
				lineno, val);
			}
			break;
		case F_UID:
			ip->st_uid = strtoul(val, &ep, 10);
			if (*ep)
				errx(1, "line %d: invalid uid %s", lineno, val);
			break;
		case F_UNAME:
			if ((pw = getpwnam(val)) == NULL)
			    errx(1, "line %d: unknown user %s", lineno, val);
			ip->st_uid = pw->pw_uid;
			break;
		}
	}
}

static void
unset(char *t, NODE *ip)
{
	char *p;

	while ((p = strtok(t, "\n\t ")))
		ip->flags &= ~parsekey(p, NULL);
}
