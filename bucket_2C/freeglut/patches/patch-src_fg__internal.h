--- src/fg_internal.h.orig	2019-09-25 10:08:07 UTC
+++ src/fg_internal.h
@@ -137,9 +137,6 @@
  * If so, perhaps there should be a config_guess.h for them. Alternatively,
  * config guesses could be placed above, just after the config.h exclusion.
  */
-#if defined(__FreeBSD__) || defined(__NetBSD__)
-#    define HAVE_USB_JS 1
-#endif
 
 #if defined(_MSC_VER) || defined(__WATCOMC__)
 /* strdup() is non-standard, for all but POSIX-2001 */
@@ -1067,6 +1064,8 @@ int         fgJoystickDetect( void );
 void        fgInitialiseJoysticks( void );
 void        fgJoystickClose( void );
 void        fgJoystickPollWindow( SFG_Window* window );
+void        fgJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes );
+void        fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes );
 
 /* InputDevice Initialisation and Closure */
 int         fgInputDeviceDetect( void );
