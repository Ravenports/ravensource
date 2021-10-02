--- src/absl/base/internal/unscaledcycleclock.cc.orig	2021-09-21 13:18:13 UTC
+++ src/absl/base/internal/unscaledcycleclock.cc
@@ -23,7 +23,7 @@
 #if defined(__powerpc__) || defined(__ppc__)
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #endif
