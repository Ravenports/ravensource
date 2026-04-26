--- tree.h.orig	2024-09-20 07:46:46 UTC
+++ tree.h
@@ -32,7 +32,16 @@
 #ifndef	_SYS_TREE_H_
 #define	_SYS_TREE_H_
 
+#ifdef __sun
+# ifndef __P
+#  define __P(protos) protos
+# endif
+# ifndef typeof
+#  define typeof __typeof__
+# endif
+#else
 #include <sys/cdefs.h>
+#endif
 
 /*
  * This file defines data structures for different types of trees:
