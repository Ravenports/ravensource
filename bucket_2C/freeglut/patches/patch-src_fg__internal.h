--- src/fg_internal.h.orig	2019-09-25 10:08:07 UTC
+++ src/fg_internal.h
@@ -1067,6 +1067,7 @@ int         fgJoystickDetect( void );
 void        fgInitialiseJoysticks( void );
 void        fgJoystickClose( void );
 void        fgJoystickPollWindow( SFG_Window* window );
+void        fgJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes );
 
 /* InputDevice Initialisation and Closure */
 int         fgInputDeviceDetect( void );
