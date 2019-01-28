diff --git src/xlib/main.c src/xlib/main.c
index 6ea90be7..773d22ca 100644
--- src/xlib/main.c
+++ src/xlib/main.c
@@ -92,31 +92,8 @@ void init_ptt(void) {
 
 
 
-#ifdef __linux__
-#include <linux/input.h>
-static bool linux_check_ptt(void) {
-    /* First, we try for direct access to the keyboard. */
-    int ptt_key = KEY_LEFTCTRL; // TODO allow user to change this...
-    if (ptt_keyboard_handle) {
-        /* Nice! we have direct access to the keyboard! */
-        char key_map[KEY_MAX / 8 + 1]; // Create a byte array the size of the number of keys
-        memset(key_map, 0, sizeof(key_map));
-        ioctl(fileno(ptt_keyboard_handle), EVIOCGKEY(sizeof(key_map)), key_map); // Fill the keymap with the current
-                                                                                 // keyboard state
-        int keyb = key_map[ptt_key / 8]; // The key we want (and the seven others around it)
-        int mask = 1 << (ptt_key % 8);   // Put 1 in the same column as our key state
-
-        if (keyb & mask) {
-            LOG_TRACE("XLIB", "PTT key is down" );
-            return true;
-        } else {
-            LOG_TRACE("XLIB", "PTT key is up" );
-            return false;
-        }
-    }
-    /* Okay nope, lets' fallback to xinput... *pouts*
-     * Fall back to Querying the X for the current keymap. */
-    ptt_key       = XKeysymToKeycode(display, XK_Control_L);
+static bool check_ptt(void) {
+    int ptt_key   = XKeysymToKeycode(display, XK_Control_L); // TODO allow user to change this...
     char keys[32] = { 0 };
     /* We need our own connection, so that we don't block the main display... No idea why... */
     if (ptt_display) {
@@ -134,11 +111,6 @@ static bool linux_check_ptt(void) {
                 "keyboard.\nDisable push to talk to suppress this message.\n");
     return false;
 }
-#else
-static bool bsd_check_ptt(void) {
-    return false;
-}
-#endif
 
 bool check_ptt_key(void) {
     if (!settings.push_to_talk) {
@@ -146,11 +118,7 @@ bool check_ptt_key(void) {
         return true; /* If push to talk is disabled, return true. */
     }
 
-#ifdef __linux__
-    return linux_check_ptt();
-#else
-    return bsd_check_ptt();
-#endif
+    return check_ptt();
 }
 
 void exit_ptt(void) {
