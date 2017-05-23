/*
 * rpc_util.h, Useful definitions for the RPC protocol compiler
 */
#include <sys/types.h>
#include <stdlib.h>

#define	XALLOC(object)   (object *) xmalloc(sizeof(object))

#define	s_print	(void) sprintf
#define	f_print (void) fprintf

#ifndef __unused
#define __unused        __attribute__((__unused__))
#endif

struct list {
	definition *val;
	struct list *next;
};
typedef struct list list;

struct xdrfunc {
	const char *name;
	int pointerp;
	struct xdrfunc *next;
};
typedef struct xdrfunc xdrfunc;

struct commandline {
	int cflag;		/* xdr C routines */
	int hflag;		/* header file */
	int lflag;		/* client side stubs */
	int mflag;		/* server side stubs */
	int nflag;		/* netid flag */
	int sflag;		/* server stubs for the given transport */
	int tflag;		/* dispatch Table file */
	int Ssflag;		/* produce server sample code */
	int Scflag;		/* produce client sample code */
	int makefileflag;       /* Generate a template Makefile */
	const char *infile;	/* input module name */
	const char *outfile;	/* output module name */
};

#define	PUT 1
#define	GET 2

/*
 * Global variables
 */
#define	MAXLINESIZE 1024
extern char curline[MAXLINESIZE];
extern char *where;
extern int linenum;
extern int tirpc_socket;

extern const char *infilename;
extern FILE *fout;
extern FILE *fin;

extern list *defined;


extern bas_type *typ_list_h;
extern bas_type *typ_list_t;
extern xdrfunc *xdrfunc_head, *xdrfunc_tail;

/*
 * All the option flags
 */
extern int inetdflag;
extern int pmflag;
extern int tblflag;
extern int logflag;
extern int newstyle;
extern int CCflag;     /* C++ flag */
extern int tirpcflag; /* flag for generating tirpc code */
extern int inline_size; /* if this is 0, then do not generate inline code */
extern int mtflag;

/*
 * Other flags related with inetd jumpstart.
 */
extern int indefinitewait;
extern int exitnow;
extern int timerflag;

extern int nonfatalerrors;

extern pid_t childpid;

/*
 * rpc_util routines
 */
void		reinitialize(void);
void		crash(void);
void		add_type(int, const char *);
void		storeval(list **, definition *);
void		*xmalloc(size_t);
void		*xrealloc(void *, size_t);
char		*xstrdup(const char *);
char		*make_argname(const char *, const char *);

#define	STOREVAL(list,item)	\
	storeval(list,item)

definition	*findval(list *, const char *, int (*)(definition *, const char *));

#define	FINDVAL(list,item,finder) \
	findval(list, item, finder)

const char	*fixtype(const char *);
const char	*stringfix(const char *);
char		*locase(const char *);
void		pvname_svc(const char *, const char *);
void		pvname(const char *, const char *);
void		ptype(const char *, const char *, int);
int		isvectordef(const char *, relation);
int		streq(const char *, const char *);
void		error(const char *);
void		expected1(tok_kind);
void		expected2(tok_kind, tok_kind);
void		expected3(tok_kind, tok_kind, tok_kind);
void		tabify(FILE *, int);
void		record_open(const char *);
bas_type	*find_type(const char *);

/*
 * rpc_cout routines
 */
void		emit(definition *);

/*
 * rpc_hout routines
 */
void		pdeclaration(const char *, declaration *, int, const char *);
void		print_datadef(definition *, int);
void		print_funcdef(definition *, int);
void		print_xdr_func_def(const char *, int);

/*
 * rpc_svcout routines
 */
void		write_most(const char *, int, int);
void		write_rest(void);
void		write_programs(const char *);
void		write_svc_aux(int);
void		write_inetd_register(const char *);
void		write_netid_register(const char *);
void		write_nettype_register(const char *);
int		nullproc(proc_list *);

/*
 * rpc_clntout routines
 */
void		write_stubs(void);
void		printarglist(proc_list *, const char *, const char *,
			     const char *);

/*
 * rpc_tblout routines
 */
void		write_tables(void);

/*
 * rpc_sample routines
 */
void		write_sample_svc(definition *);
int		write_sample_clnt(definition *);
void		write_sample_clnt_main(void);
void		add_sample_msg(void);
