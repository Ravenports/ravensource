--- utils.h.orig	2023-10-09 09:18:22 UTC
+++ utils.h
@@ -10,6 +10,8 @@
 
 #ifdef HAVE_SYS_TREE_H
 #include <sys/tree.h>
+#elif defined(__linux__)
+#include <bsd/sys/tree.h>
 #else
 #include "tree.h"
 #endif
