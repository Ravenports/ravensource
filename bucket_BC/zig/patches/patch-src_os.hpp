--- /home/tse/Packages/zig-0.4.0.orig/src/os.hpp	2019-04-08 22:41:41.000000000 +0300
+++ src/os.hpp	2019-04-26 14:16:42.462393000 +0300
@@ -27,6 +27,8 @@
 #define ZIG_OS_FREEBSD
 #elif defined(__NetBSD__)
 #define ZIG_OS_NETBSD
+#elif defined(__DragonFly__)
+#define ZIG_OS_DRAGONFLY
 #else
 #define ZIG_OS_UNKNOWN
 #endif
