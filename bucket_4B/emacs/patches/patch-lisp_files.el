--- lisp/files.el.orig	2023-07-09 08:54:39 UTC
+++ lisp/files.el
@@ -7602,7 +7602,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls'-like program.
 This is used by `insert-directory' and `dired-insert-directory'
 \(thus, also by `dired').")
