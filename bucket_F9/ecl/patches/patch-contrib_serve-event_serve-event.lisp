--- contrib/serve-event/serve-event.lisp.orig	2024-05-10 11:13:55 UTC
+++ contrib/serve-event/serve-event.lisp
@@ -45,6 +45,7 @@
 
 (clines
  "#include <errno.h>"
+ "#include <string.h>"
  "#include <sys/select.h>")
 
 (eval-when (:compile-toplevel :execute)
