--- lisp/files.el.orig	2018-05-25 08:53:30 UTC
+++ lisp/files.el
@@ -6431,7 +6431,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls' program used by `insert-directory'.")
 
 (defcustom directory-free-space-program (purecopy "df")
