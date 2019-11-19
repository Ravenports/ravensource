--- src/xlib/main.c.orig	2019-11-19 20:22:58 UTC
+++ src/xlib/main.c
@@ -93,9 +93,9 @@ void init_ptt(void) {
 
 
 
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
 #include <linux/input.h>
-#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#elif defined(__DragonFly__)
 #include <dev/misc/evdev/input.h>
 #endif
 
