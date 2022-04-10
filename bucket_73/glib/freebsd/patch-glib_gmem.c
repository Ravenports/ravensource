--- glib/gmem.c.orig	2022-04-10 09:47:39.187704000 +0200
+++ glib/gmem.c	2022-04-10 09:51:18.476098000 +0200
@@ -36,7 +36,9 @@
 
 #if defined(HAVE_MEMALIGN) || defined(HAVE__ALIGNED_MALLOC)
 /* Required for _aligned_malloc() and _aligned_free() on Windows */
+#if !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
 #endif
 
 #ifdef HAVE__ALIGNED_MALLOC
