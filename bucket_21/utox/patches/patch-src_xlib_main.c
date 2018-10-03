diff --git src/xlib/main.c src/xlib/main.c
index 6ea90be7..4ca170e7 100644
--- src/xlib/main.c
+++ src/xlib/main.c
@@ -94,6 +94,11 @@ void init_ptt(void) {
 
 #ifdef __linux__
 #include <linux/input.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#include <dev/misc/evdev/input.h>
+#endif
+
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
 static bool linux_check_ptt(void) {
     /* First, we try for direct access to the keyboard. */
     int ptt_key = KEY_LEFTCTRL; // TODO allow user to change this...
@@ -146,7 +151,7 @@ bool check_ptt_key(void) {
         return true; /* If push to talk is disabled, return true. */
     }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
     return linux_check_ptt();
 #else
     return bsd_check_ptt();
