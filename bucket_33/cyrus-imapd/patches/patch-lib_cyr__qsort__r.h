--- lib/cyr_qsort_r.h.orig	2024-08-14 03:08:23 UTC
+++ lib/cyr_qsort_r.h
@@ -33,7 +33,7 @@
 #endif
 
 #if !defined(HAVE_GLIBC_QSORT_R) && \
-	(defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__))
+	(defined(__APPLE__))
 #define HAVE_BSD_QSORT_R
 #endif
 
