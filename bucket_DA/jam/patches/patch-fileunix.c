--- fileunix.c.orig	2019-06-20 23:12:56 UTC
+++ fileunix.c
@@ -47,6 +47,8 @@
 # define PORTAR 1
 # endif
 
+#include <unistd.h>
+
 # if defined( OS_RHAPSODY ) || \
      defined( OS_DARWIN ) || \
      defined( OS_MACOSX ) || \
