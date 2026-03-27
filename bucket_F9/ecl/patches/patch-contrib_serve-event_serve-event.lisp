--- contrib/serve-event/serve-event.lisp.orig	2026-03-27 08:12:03 UTC
+++ contrib/serve-event/serve-event.lisp
@@ -45,6 +45,7 @@
 
 (clines
  "#include <errno.h>"
+ "#include <string.h>"
  "#include <sys/select.h>")
 
 (eval-when (:compile-toplevel :execute)
