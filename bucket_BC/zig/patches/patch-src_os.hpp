--- src/os.hpp.orig	2019-04-08 19:41:41 UTC
+++ src/os.hpp
@@ -27,6 +27,8 @@
 #define ZIG_OS_FREEBSD
 #elif defined(__NetBSD__)
 #define ZIG_OS_NETBSD
+#elif defined(__DragonFly__)
+#define ZIG_OS_DRAGONFLY
 #else
 #define ZIG_OS_UNKNOWN
 #endif
