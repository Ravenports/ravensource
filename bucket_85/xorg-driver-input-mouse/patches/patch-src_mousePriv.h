--- src/mousePriv.h.orig	2018-06-19 04:36:21 UTC
+++ src/mousePriv.h
@@ -63,8 +63,6 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
-    float       fracdx,fracdy;
-    float       sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
