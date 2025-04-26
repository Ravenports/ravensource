--- libs/process/src/ext/exe.cpp.orig	2025-04-03 11:37:29 UTC
+++ libs/process/src/ext/exe.cpp
@@ -39,7 +39,7 @@
 #if (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
-#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
 #endif
 #endif
