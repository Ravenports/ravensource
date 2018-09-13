#include <sys/param.h>
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <fts.h>
#ifdef USE_MD5
#include <md5.h>
#endif
#ifdef USE_SHA1
#include "sha.h"
#include "sha1hl.h"
#endif
#ifdef USE_RMD160
#include <ripemd.h>
#endif
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "mtree.h"
#include "extern.h"

static const char *ftype(u_int);

#define	INDENTNAMELEN	8
#define	LABEL \
	if (!label++) { \
		len = printf("%s changed\n", RP(p)); \
		tab = "\t"; \
	}

int
compare(NODE *s, FTSENT *p)
{
	u_long len, val;
	int fd, label;
	char *cp, *fflags;
	const char *tab = "";

	label = 0;
	switch(s->type) {
	case F_BLOCK:
		if (!S_ISBLK(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_CHAR:
		if (!S_ISCHR(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_DIR:
		if (!S_ISDIR(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_FIFO:
		if (!S_ISFIFO(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_FILE:
		if (!S_ISREG(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_LINK:
		if (!S_ISLNK(p->fts_statp->st_mode))
			goto typeerr;
		break;
	case F_SOCK:
		if (!S_ISSOCK(p->fts_statp->st_mode)) {
typeerr:		LABEL;
			printf("\ttype expected %s found %s\n",
			    ftype(s->type), inotype(p->fts_statp->st_mode));
			return (label);
		}
		break;
	}
	/* Set the uid/gid first, then set the mode. */
	if (s->flags & (F_UID | F_UNAME) && s->st_uid != p->fts_statp->st_uid) {
		LABEL;
		printf("%suser expected %lu found %lu",
		    tab, (u_long)s->st_uid, (u_long)p->fts_statp->st_uid);
		if (uflag)
			if (chown(p->fts_accpath, s->st_uid, -1))
				printf(" not modified: %s\n",
				    strerror(errno));
			else
				printf(" modified\n");
		else
			printf("\n");
		tab = "\t";
	}
	if (s->flags & (F_GID | F_GNAME) && s->st_gid != p->fts_statp->st_gid) {
		LABEL;
		printf("%sgid expected %lu found %lu",
		    tab, (u_long)s->st_gid, (u_long)p->fts_statp->st_gid);
		if (uflag)
			if (chown(p->fts_accpath, -1, s->st_gid))
				printf(" not modified: %s\n",
				    strerror(errno));
			else
				printf(" modified\n");
		else
			printf("\n");
		tab = "\t";
	}
	if (s->flags & F_MODE &&
	    !S_ISLNK(p->fts_statp->st_mode) &&
	    s->st_mode != (p->fts_statp->st_mode & MBITS)) {
		LABEL;
		printf("%spermissions expected %#o found %#o",
		    tab, s->st_mode, p->fts_statp->st_mode & MBITS);
		if (uflag)
			if (chmod(p->fts_accpath, s->st_mode))
				printf(" not modified: %s\n",
				    strerror(errno));
			else
				printf(" modified\n");
		else
			printf("\n");
		tab = "\t";
	}
	if (s->flags & F_NLINK && s->type != F_DIR &&
	    s->st_nlink != p->fts_statp->st_nlink) {
		LABEL;
		printf("%slink_count expected %u found %u\n",
		    tab, (unsigned int)s->st_nlink, (unsigned int)p->fts_statp->st_nlink);
		tab = "\t";
	}
	if (s->flags & F_SIZE && s->st_size != p->fts_statp->st_size &&
		!S_ISDIR(p->fts_statp->st_mode)) {
		LABEL;
		printf("%ssize expected %jd found %jd\n", tab,
		    (intmax_t)s->st_size, (intmax_t)p->fts_statp->st_size);
		tab = "\t";
	}
	/*
	 * XXX
	 * Catches nano-second differences, but doesn't display them.
	 */
	if ((s->flags & F_TIME) &&
#ifdef __sunlinux__
	     ((s->st_mtimespec.tv_sec != p->fts_statp->st_mtim.tv_sec) ||
	     (s->st_mtimespec.tv_nsec != p->fts_statp->st_mtim.tv_nsec))) {
		LABEL;
		printf("%smodification time expected %.24s ",
		    tab, ctime(&s->st_mtimespec.tv_sec));
		printf("found %.24s\n",
		    ctime(&p->fts_statp->st_mtim.tv_nsec));
		tab = "\t";
#else
	     ((s->st_mtimespec.tv_sec != p->fts_statp->st_mtimespec.tv_sec) ||
	     (s->st_mtimespec.tv_nsec != p->fts_statp->st_mtimespec.tv_nsec))) {
		LABEL;
		printf("%smodification time expected %.24s ",
		    tab, ctime(&s->st_mtimespec.tv_sec));
		printf("found %.24s\n",
		    ctime(&p->fts_statp->st_mtimespec.tv_sec));
		tab = "\t";
#endif
	}
	if (s->flags & F_CKSUM) {
		if ((fd = open(p->fts_accpath, O_RDONLY, 0)) < 0) {
			LABEL;
			printf("%scksum: %s: %s\n",
			    tab, p->fts_accpath, strerror(errno));
			tab = "\t";
		} else if (crc(fd, &val, &len)) {
			close(fd);
			LABEL;
			printf("%scksum: %s: %s\n",
			    tab, p->fts_accpath, strerror(errno));
			tab = "\t";
		} else {
			close(fd);
			if (s->cksum != val) {
				LABEL;
				printf("%scksum expected %lu found %lu\n",
				    tab, s->cksum, val);
				tab = "\t";
			}
		}
	}
#ifndef __sunlinux__
	/*
	 * XXX
	 * since chflags(2) will reset file times, the utimes() above
	 * may have been useless!  oh well, we'd rather have correct
	 * flags, rather than times?
	 */
	if ((s->flags & F_FLAGS) && s->st_flags != p->fts_statp->st_flags) {
		LABEL;
		fflags = flags_to_string(s->st_flags);
		printf("%sflags expected \"%s\"", tab, fflags);
		free(fflags);

		fflags = flags_to_string(p->fts_statp->st_flags);
		printf(" found \"%s\"", fflags);
		free(fflags);

		if (uflag)
			if (chflags(p->fts_accpath, s->st_flags))
				printf(" not modified: %s\n",
				    strerror(errno));
			else
				printf(" modified\n");
		else
			printf("\n");
		tab = "\t";
	}
#endif /* ! __sunlinux__ */
#ifdef USE_MD5
	if (s->flags & F_MD5) {
		char *new_digest, buf[33];

		new_digest = MD5File(p->fts_accpath, buf);
		if (!new_digest) {
			LABEL;
			printf("%sMD5: %s: %s\n", tab, p->fts_accpath,
			       strerror(errno));
			tab = "\t";
		} else if (strcmp(new_digest, s->md5digest)) {
			LABEL;
			printf("%sMD5 expected %s found %s\n", tab, s->md5digest,
			       new_digest);
			tab = "\t";
		}
	}
#endif /* MD5 */
#ifdef USE_SHA1
	if (s->flags & F_SHA1) {
		char *new_digest, buf[41];

		new_digest = SHA1_File(p->fts_accpath, buf);
		if (!new_digest) {
			LABEL;
			printf("%sSHA-1: %s: %s\n", tab, p->fts_accpath,
			       strerror(errno));
			tab = "\t";
		} else if (strcmp(new_digest, s->sha1digest)) {
			LABEL;
			printf("%sSHA-1 expected %s found %s\n", 
			       tab, s->sha1digest, new_digest);
			tab = "\t";
		}
	}
#endif /* SHA1 */
#ifdef USE_RMD160
	if (s->flags & F_RMD160) {
		char *new_digest, buf[41];

		new_digest = RIPEMD160_File(p->fts_accpath, buf);
		if (!new_digest) {
			LABEL;
			printf("%sRIPEMD160: %s: %s\n", tab,
			       p->fts_accpath, strerror(errno));
			tab = "\t";
		} else if (strcmp(new_digest, s->rmd160digest)) {
			LABEL;
			printf("%sRIPEMD160 expected %s found %s\n",
			       tab, s->rmd160digest, new_digest);
			tab = "\t";
		}
	}
#endif /* RMD160 */

	if (s->flags & F_SLINK &&
	    strcmp(cp = rlink(p->fts_accpath), s->slink)) {
		LABEL;
		printf("%slink_ref expected %s found %s\n",
		      tab, s->slink, cp);
	}
	return (label);
}

const char *
inotype(u_int type)
{
	switch(type & S_IFMT) {
	case S_IFBLK:
		return ("block");
	case S_IFCHR:
		return ("char");
	case S_IFDIR:
		return ("dir");
	case S_IFIFO:
		return ("fifo");
	case S_IFREG:
		return ("file");
	case S_IFLNK:
		return ("link");
	case S_IFSOCK:
		return ("socket");
	default:
		return ("unknown");
	}
	/* NOTREACHED */
}

static const char *
ftype(u_int type)
{
	switch(type) {
	case F_BLOCK:
		return ("block");
	case F_CHAR:
		return ("char");
	case F_DIR:
		return ("dir");
	case F_FIFO:
		return ("fifo");
	case F_FILE:
		return ("file");
	case F_LINK:
		return ("link");
	case F_SOCK:
		return ("socket");
	default:
		return ("unknown");
	}
	/* NOTREACHED */
}

char *
rlink(char *name)
{
	static char lbuf[MAXPATHLEN];
	int len;

	if ((len = readlink(name, lbuf, sizeof(lbuf) - 1)) == -1)
		err(1, "line %d: %s", lineno, name);
	lbuf[len] = '\0';
	return (lbuf);
}
