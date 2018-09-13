#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define	KEYDEFAULT \
	(F_GID | F_MODE | F_NLINK | F_SIZE | F_SLINK | F_TIME | F_UID | F_FLAGS)

#define	MISMATCHEXIT	2

typedef struct _node {
	struct _node	*parent, *child;	/* up, down */
	struct _node	*prev, *next;		/* left, right */
	off_t	st_size;			/* size */
	struct timespec	st_mtimespec;		/* last modification time */
	u_long	cksum;				/* check sum */
	char	*md5digest;			/* MD5 digest */
	char	*sha1digest;			/* SHA-1 digest */
	char	*rmd160digest;			/* RIPEMD160 digest */
	char	*slink;				/* symbolic link reference */
	uid_t	st_uid;				/* uid */
	gid_t	st_gid;				/* gid */
#define	MBITS	(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
	mode_t	st_mode;			/* mode */
	u_long	st_flags;			/* flags */
	nlink_t	st_nlink;			/* link count */

#define	F_CKSUM	0x0001				/* check sum */
#define	F_DONE	0x0002				/* directory done */
#define	F_GID	0x0004				/* gid */
#define	F_GNAME	0x0008				/* group name */
#define	F_IGN	0x0010				/* ignore */
#define	F_MAGIC	0x0020				/* name has magic chars */
#define	F_MODE	0x0040				/* mode */
#define	F_NLINK	0x0080				/* number of links */
#define	F_SIZE	0x0100				/* size */
#define	F_SLINK	0x0200				/* link count */
#define	F_TIME	0x0400				/* modification time */
#define	F_TYPE	0x0800				/* file type */
#define	F_UID	0x1000				/* uid */
#define	F_UNAME	0x2000				/* user name */
#define	F_VISIT	0x4000				/* file visited */
#define F_MD5	0x8000				/* MD5 digest */
#define F_NOCHANGE 0x10000			/* If owner/mode "wrong", do */
						/* not change */
#define	F_SHA1	0x20000				/* SHA-1 digest */
#define	F_RMD160 0x40000			/* RIPEMD160 digest */
#define	F_FLAGS	0x80000				/* file flags */
	u_int	flags;				/* items set */

#define	F_BLOCK	0x001				/* block special */
#define	F_CHAR	0x002				/* char special */
#define	F_DIR	0x004				/* directory */
#define	F_FIFO	0x008				/* fifo */
#define	F_FILE	0x010				/* regular file */
#define	F_LINK	0x020				/* symbolic link */
#define	F_SOCK	0x040				/* socket */
	u_char	type;				/* file type */

	char	name[1];			/* file name (must be last) */
} NODE;

#define	RP(p)	\
	((p)->fts_path[0] == '.' && (p)->fts_path[1] == '/' ? \
	    (p)->fts_path + 2 : (p)->fts_path)
