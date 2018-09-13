#include <stdint.h>

#if defined __linux__ || defined __sun__
#define __sunlinux__
#endif

#ifdef MAXPATHLEN
extern char fullpath[MAXPATHLEN];
#endif
extern int dflag, eflag, iflag, nflag, qflag, rflag, sflag, uflag;
extern int ftsoptions;
extern int lineno;
extern uint32_t crc_total;
extern u_int keys;

int	 compare(NODE *, FTSENT *);
int	 crc(int, u_long *, u_long *);
void	 cwalk(void);
#ifndef __sunlinux__
char	*flags_to_string(u_long);
#endif

const char *inotype(u_int);
u_int	 parsekey(char *, int *);
char	*rlink(char *);
NODE	*spec(void);
int	 verify(void);

int	 check_excludes(const char *, const char *);
void	 init_excludes(void);
void	 read_excludes_file(const char *);
