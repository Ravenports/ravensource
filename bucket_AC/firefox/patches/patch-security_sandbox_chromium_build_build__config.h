--- security/sandbox/chromium/build/build_config.h.orig	2024-12-09 19:17:31 UTC
+++ security/sandbox/chromium/build/build_config.h
@@ -51,7 +51,7 @@
 #define OS_WIN 1
 #elif defined(__Fuchsia__)
 #define OS_FUCHSIA 1
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #define OS_FREEBSD 1
 #elif defined(__NetBSD__)
 #define OS_NETBSD 1
