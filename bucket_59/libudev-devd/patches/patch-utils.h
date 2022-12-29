--- utils.h.orig	2021-09-04 13:20:25 UTC
+++ utils.h
@@ -10,6 +10,8 @@
 
 #ifdef HAVE_SYS_TREE_H
 #include <sys/tree.h>
+#elif defined(__linux__)
+#include <bsd/sys/tree.h>
 #else
 #include "tree.h"
 #endif
