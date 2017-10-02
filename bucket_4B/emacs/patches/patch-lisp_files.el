--- lisp/files.el.orig	2017-04-14 15:02:47 UTC
+++ lisp/files.el
@@ -6217,7 +6217,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls' program used by `insert-directory'.")
 
 (defcustom directory-free-space-program (purecopy "df")
