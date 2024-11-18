--- exp_tty.h.orig	2018-02-02 19:15:52 UTC
+++ exp_tty.h
@@ -19,6 +19,7 @@ void exp_tty_raw(int set);
 void exp_tty_echo(int set);
 void exp_tty_break(Tcl_Interp *interp, int fd);
 int exp_tty_raw_noecho(Tcl_Interp *interp, exp_tty *tty_old, int *was_raw, int *was_echo);
+int exp_tty_cooked_echo(Tcl_Interp *interp, exp_tty *tty_old, int *was_raw, int *was_echo);
 int exp_israw(void);
 int exp_isecho(void);
 
