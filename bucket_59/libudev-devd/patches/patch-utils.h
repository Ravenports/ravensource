--- utils.h.orig	2024-09-20 07:46:46 UTC
+++ utils.h
@@ -37,6 +37,8 @@
 
 #ifdef HAVE_SYS_TREE_H
 #include <sys/tree.h>
+#elif defined(__linux__)
+#include <bsd/sys/tree.h>
 #else
 #include "tree.h"
 #endif
