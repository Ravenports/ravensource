--- src/util/build_config.h.orig	2020-08-12 19:30:44 UTC
+++ src/util/build_config.h
@@ -40,6 +40,8 @@
 #define OS_WIN 1
 #elif defined(__Fuchsia__)
 #define OS_FUCHSIA 1
+#elif defined(__DragonFly__)
+#define OS_DRAGONFLY 1
 #elif defined(__FreeBSD__)
 #define OS_FREEBSD 1
 #elif defined(__NetBSD__)
@@ -64,13 +66,14 @@
 
 // For access to standard BSD features, use OS_BSD instead of a
 // more specific macro.
-#if defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD)
+#if defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_DRAGONFLY)
 #define OS_BSD 1
 #endif
 
 // For access to standard POSIXish features, use OS_POSIX instead of a
 // more specific macro.
 #if defined(OS_AIX) || defined(OS_ANDROID) || defined(OS_ASMJS) ||    \
+    defined(OS_DRAGONFLY) || \
     defined(OS_FREEBSD) || defined(OS_LINUX) || defined(OS_MACOSX) || \
     defined(OS_NACL) || defined(OS_NETBSD) || defined(OS_OPENBSD) ||  \
     defined(OS_QNX) || defined(OS_SOLARIS) || defined(OS_HAIKU) || \
