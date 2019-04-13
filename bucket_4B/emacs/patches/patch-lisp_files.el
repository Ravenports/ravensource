--- lisp/files.el.orig	2019-01-07 14:26:06 UTC
+++ lisp/files.el
@@ -6450,7 +6450,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls' program used by `insert-directory'.")
 
 (defcustom directory-free-space-program (purecopy "df")
