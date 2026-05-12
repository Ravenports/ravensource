--- contrib/serve-event/serve-event.lisp.orig	2026-05-05 09:20:39 UTC
+++ contrib/serve-event/serve-event.lisp
@@ -45,6 +45,7 @@
 
 (clines
  "#include <errno.h>"
+ "#include <string.h>"
  "#include <sys/select.h>")
 
 (eval-when (:compile-toplevel :execute)
