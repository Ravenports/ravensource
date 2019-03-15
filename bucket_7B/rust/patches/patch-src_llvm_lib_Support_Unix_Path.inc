--- src/llvm/lib/Support/Unix/Path.inc.orig	2018-12-18 09:55:21 UTC
+++ src/llvm/lib/Support/Unix/Path.inc
@@ -54,13 +54,13 @@
 
 #include <sys/types.h>
 #if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) &&   \
-    !defined(__linux__)
+    !defined(__DragonFly__) && !defined(__linux__)
 #include <sys/statvfs.h>
 #define STATVFS statvfs
 #define FSTATVFS fstatvfs
 #define STATVFS_F_FRSIZE(vfs) vfs.f_frsize
 #else
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/mount.h>
 #include <sys/param.h>
 #elif defined(__linux__)
