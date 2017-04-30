enum defkind {
	DEF_CONST,
	DEF_STRUCT,
	DEF_UNION,
	DEF_ENUM,
	DEF_TYPEDEF,
	DEF_PROGRAM
};
typedef enum defkind defkind;

typedef const char *const_def;

enum relation {
	REL_VECTOR,	/* fixed length array */
	REL_ARRAY,	/* variable length array */
	REL_POINTER,	/* pointer */
	REL_ALIAS,	/* simple */
};
typedef enum relation relation;

struct typedef_def {
	const char *old_prefix;
	const char *old_type;
	relation rel;
	const char *array_max;
};
typedef struct typedef_def typedef_def;

struct enumval_list {
	const char *name;
	const char *assignment;
	struct enumval_list *next;
};
typedef struct enumval_list enumval_list;

struct enum_def {
	enumval_list *vals;
};
typedef struct enum_def enum_def;

struct declaration {
	const char *prefix;
	const char *type;
	const char *name;
	relation rel;
	const char *array_max;
};
typedef struct declaration declaration;

struct decl_list {
	declaration decl;
	struct decl_list *next;
};
typedef struct decl_list decl_list;

struct struct_def {
	decl_list *decls;
};
typedef struct struct_def struct_def;

struct case_list {
	const char *case_name;
	int contflag;
	declaration case_decl;
	struct case_list *next;
};
typedef struct case_list case_list;

struct union_def {
	declaration enum_decl;
	case_list *cases;
	declaration *default_decl;
};
typedef struct union_def union_def;

struct arg_list {
	char *argname; /* name of struct for arg*/
	decl_list *decls;
};
	
typedef struct arg_list arg_list;

struct proc_list {
	const char *proc_name;
	const char *proc_num;
	arg_list args;
	int arg_num;
	const char *res_type;
	const char *res_prefix;
	struct proc_list *next;
};
typedef struct proc_list proc_list;

struct version_list {
	const char *vers_name;
	const char *vers_num;
	proc_list *procs;
	struct version_list *next;
};
typedef struct version_list version_list;

struct program_def {
	const char *prog_num;
	version_list *versions;
};
typedef struct program_def program_def;

struct definition {
	const char *def_name;
	defkind def_kind;
	union {
		const_def co;
		struct_def st;
		union_def un;
		enum_def en;
		typedef_def ty;
		program_def pr;
	} def;
};
typedef struct definition definition;

definition *get_definition(void);

struct bas_type
{
  const char *name;
  int length;
  struct bas_type *next;
};

typedef struct bas_type bas_type;
