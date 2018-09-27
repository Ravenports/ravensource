--- compat/tree.h.orig	2018-09-28 12:31:52.435530000 +0300
+++ compat/tree.h	2018-09-28 12:33:41.057478000 +0300
@@ -27,6 +27,8 @@
 #ifndef	_SYS_TREE_H_
 #define	_SYS_TREE_H_
 
+#include <stddef.h>
+
 /*
  * This file defines data structures for different types of trees:
  * splay trees and red-black trees.
