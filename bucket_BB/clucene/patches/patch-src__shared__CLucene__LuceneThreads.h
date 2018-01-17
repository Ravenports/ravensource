--- src/shared/CLucene/LuceneThreads.h.orig	2011-03-17 00:21:07 UTC
+++ src/shared/CLucene/LuceneThreads.h
@@ -7,6 +7,9 @@
 #ifndef _LuceneThreads_h
 #define  _LuceneThreads_h
 
+#if defined(_CL_HAVE_PTHREAD)
+#include <pthread.h>
+#endif
 
 CL_NS_DEF(util)
 class CLuceneThreadIdCompare;
