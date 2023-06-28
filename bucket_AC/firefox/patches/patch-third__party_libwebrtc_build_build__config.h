--- third_party/libwebrtc/build/build_config.h.orig	2023-06-08 22:09:49 UTC
+++ third_party/libwebrtc/build/build_config.h
@@ -76,7 +76,7 @@
 #define OS_WIN 1
 #elif defined(__Fuchsia__)
 #define OS_FUCHSIA 1
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #define OS_FREEBSD 1
 #elif defined(__NetBSD__)
 #define OS_NETBSD 1
