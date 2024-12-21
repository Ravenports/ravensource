--- src/xshmfence_futex.h.orig	2024-12-14 02:05:01 UTC
+++ src/xshmfence_futex.h
@@ -28,6 +28,7 @@
 
 #ifdef HAVE_UMTX
 
+#include <sys/limits.h>
 #include <sys/types.h>
 #include <sys/umtx.h>
 #include <limits.h>
