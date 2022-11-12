--- src/xshmfence_futex.h.orig	2022-10-18 16:50:22 UTC
+++ src/xshmfence_futex.h
@@ -28,6 +28,7 @@
 
 #ifdef HAVE_UMTX
 
+#include <sys/limits.h>
 #include <sys/types.h>
 #include <sys/umtx.h>
 #include <limits.h>
