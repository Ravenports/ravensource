--- lisp/files.el.orig	2020-07-29 21:40:41 UTC
+++ lisp/files.el
@@ -6766,7 +6766,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls' program used by `insert-directory'.")
 
 (defcustom directory-free-space-program (purecopy "df")
