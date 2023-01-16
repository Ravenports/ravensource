--- src/absl/base/internal/unscaledcycleclock.cc.orig	2023-01-11 14:22:54 UTC
+++ src/absl/base/internal/unscaledcycleclock.cc
@@ -23,7 +23,7 @@
 #if defined(__powerpc__) || defined(__ppc__)
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 // clang-format off
 // This order does actually matter =(.
 #include <sys/types.h>
