#include <sys/param.h>
#include <sys/stat.h>
#include <err.h>
#include <string.h>
#include <errno.h>
#include <fts.h>
#include <stdio.h>
#include <unistd.h>
#include "mtree.h"
#include "extern.h"

int ftsoptions = FTS_PHYSICAL;
int cflag, dflag, eflag, iflag, nflag, qflag, rflag, sflag, uflag, Uflag;
u_int keys;
char fullpath[MAXPATHLEN];

static void usage(void);

int
main(int argc, char *argv[])
{
	int ch;
	char *dir, *p;
	int status;

	dir = NULL;
	keys = KEYDEFAULT;
	init_excludes();

	while ((ch = getopt(argc, argv, "cdef:iK:k:LnPp:qrs:UuxX:")) != -1)
		switch((char)ch) {
		case 'c':
			cflag = 1;
			break;
		case 'd':
			dflag = 1;
			break;
		case 'e':
			eflag = 1;
			break;
		case 'f':
			if (!(freopen(optarg, "r", stdin)))
				err(1, "%s", optarg);
			break;
		case 'i':
			iflag = 1;
			break;
		case 'K':
			while ((p = strsep(&optarg, " \t,")) != NULL)
				if (*p != '\0')
					keys |= parsekey(p, NULL);
			break;
		case 'k':
			keys = F_TYPE;
			while ((p = strsep(&optarg, " \t,")) != NULL)
				if (*p != '\0')
					keys |= parsekey(p, NULL);
			break;
		case 'L':
			ftsoptions &= ~FTS_PHYSICAL;
			ftsoptions |= FTS_LOGICAL;
			break;
		case 'n':
			nflag = 1;
			break;
		case 'P':
			ftsoptions &= ~FTS_LOGICAL;
			ftsoptions |= FTS_PHYSICAL;
			break;
		case 'p':
			dir = optarg;
			break;
		case 'q':
			qflag = 1;
			break;
		case 'r':
			rflag = 1;
			break;
		case 's':
			sflag = 1;
			crc_total = ~strtol(optarg, &p, 0);
			if (*p)
				errx(1, "illegal seed value -- %s", optarg);
			break;
		case 'U':
			Uflag = 1;
			uflag = 1;
			break;
		case 'u':
			uflag = 1;
			break;
		case 'x':
			ftsoptions |= FTS_XDEV;
			break;
		case 'X':
			read_excludes_file(optarg);
			break;
		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	if (argc)
		usage();

	if (dir && chdir(dir))
		err(1, "%s", dir);

	if ((cflag || sflag) && !getcwd(fullpath, sizeof(fullpath)))
		errx(1, "%s", fullpath);

	if (cflag) {
		cwalk();
		exit(0);
	}
	status = verify();
	if (Uflag & (status == MISMATCHEXIT))
		status = 0;
	exit(status);
}

static void
usage(void)
{

	fprintf(stderr,
"usage: mtree [-LPUcdeinqrux] [-f spec] [-K key] [-k key] [-p path] [-s seed]\n"
"\t[-X excludes]\n");
	exit(1);
}
