--- lib/cyr_qsort_r.h.orig	2026-09-09 01:06:41 UTC
+++ lib/cyr_qsort_r.h
@@ -31,7 +31,7 @@
 #endif
 
 #if !defined(HAVE_GLIBC_QSORT_R) && \
-	(defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__))
+	(defined(__APPLE__))
 #define HAVE_BSD_QSORT_R
 #endif
 
