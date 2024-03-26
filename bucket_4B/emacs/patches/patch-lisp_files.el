--- lisp/files.el.orig	2024-01-06 12:56:30 UTC
+++ lisp/files.el
@@ -7612,7 +7612,7 @@ need to be passed verbatim to shell comm
       pattern))))
 
 
-(defvar insert-directory-program (purecopy "ls")
+(defvar insert-directory-program (purecopy "gls")
   "Absolute or relative name of the `ls'-like program.
 This is used by `insert-directory' and `dired-insert-directory'
 \(thus, also by `dired').")
