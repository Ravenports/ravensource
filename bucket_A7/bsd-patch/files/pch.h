#define OLD_FILE	0
#define NEW_FILE	1
#define INDEX_FILE	2
#define MAX_FILE	3

struct file_name {
	char *path;
	bool exists;
};

void		re_patch(void);
void		open_patch_file(const char *);
void		set_hunkmax(void);
bool		there_is_another_patch(void);
bool		another_hunk(void);
bool		pch_swap(void);
char		*pfetch(LINENUM);
unsigned short	pch_line_len(LINENUM);
LINENUM		pch_first(void);
LINENUM		pch_ptrn_lines(void);
LINENUM		pch_newfirst(void);
LINENUM		pch_repl_lines(void);
LINENUM		pch_end(void);
LINENUM		pch_context(void);
LINENUM		pch_hunk_beg(void);
char		pch_char(LINENUM);
void		do_ed_script(void);
