#include <sys/types.h>

#include <stdbool.h>
#include <stdint.h>
#include "linux_support.h"

#define	DEBUGGING

/* constants */

#define	MAXHUNKSIZE 200000	/* is this enough lines? */
#define	INITHUNKMAX 125		/* initial dynamic allocation size */
#define	INITLINELEN 4096
#define	BUFFERSIZE 4096
#define	LINENUM_MAX LONG_MAX

#define	ORIGEXT ".orig"
#define	REJEXT ".rej"

/* handy definitions */

#define	strEQ(s1,s2) (strcmp(s1, s2) == 0)
#define	strnNE(s1,s2,l) (strncmp(s1, s2, l) != 0)
#define	strnEQ(s1,s2,l) (strncmp(s1, s2, l) == 0)

/* typedefs */

typedef long    LINENUM;	/* must be signed */
enum vlevel	{ NORMAL_LEVEL, SILENT, VERBOSE };

/* globals */

extern mode_t	filemode;

extern char	*buf;		/* general purpose buffer */
extern size_t	buf_size;	/* size of general purpose buffer */

extern bool	using_plan_a;	/* try to keep everything in memory */
extern bool	out_of_mem;	/* ran out of memory in plan a */

#define	MAXFILEC 2

extern char	*filearg[MAXFILEC];
extern bool	ok_to_create_file;
extern char	*outname;
extern char	*origprae;

extern char	*TMPOUTNAME;
extern char	*TMPINNAME;
extern char	*TMPREJNAME;
extern char	*TMPPATNAME;
extern bool	toutkeep;
extern bool	trejkeep;

#ifdef DEBUGGING
extern int	debug;
#endif

extern bool	force;
extern bool	batch;
extern enum	vlevel verbosity;
extern bool	reverse;
extern bool	noreverse;
extern bool	skip_rest_of_patch;
extern int	strippath;
extern bool	canonicalize;
/* TRUE if -C was specified on command line.  */
extern bool	check_only;
extern bool	warn_on_invalid_line;
extern bool	last_line_missing_eol;


#define	CONTEXT_DIFF 1
#define	NORMAL_DIFF 2
#define	ED_DIFF 3
#define	NEW_CONTEXT_DIFF 4
#define	UNI_DIFF 5

extern int	diff_type;
extern char	*revision;	/* prerequisite revision, if any */
extern LINENUM	input_lines;	/* how long is input file in lines */

extern int	posix;

