--- src/fg_joystick.c.orig	2017-07-31 20:49:26 UTC
+++ src/fg_joystick.c
@@ -76,7 +76,7 @@ SFG_Joystick *fgJoystick [ MAX_NUM_JOYST
 /*
  * Read the raw joystick data
  */
-static void fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
+void fghJoystickRawRead( SFG_Joystick* joy, int* buttons, float* axes )
 {
     int i;
 
