--- src/mousePriv.h.orig	2022-11-02 02:44:34 UTC
+++ src/mousePriv.h
@@ -63,8 +63,6 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
-    float       fracdx,fracdy;
-    float       sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
