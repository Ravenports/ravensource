--- libraries/libedit-20140620-3.1/src/terminal.h.orig	2016-05-03 07:44:05 UTC
+++ libraries/libedit-20140620-3.1/src/terminal.h
@@ -82,14 +82,6 @@ typedef struct {
 #define	A_K_DE		6
 #define	A_K_NKEYS	7
 
-#ifdef __sun
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
 
 protected void	terminal_move_to_line(EditLine *, int);
 protected void	terminal_move_to_char(EditLine *, int);
