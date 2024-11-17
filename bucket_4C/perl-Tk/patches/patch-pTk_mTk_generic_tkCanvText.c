--- pTk/mTk/generic/tkCanvText.c.orig	2013-11-15 23:50:03 UTC
+++ pTk/mTk/generic/tkCanvText.c
@@ -1235,6 +1235,7 @@ GetTextIndex(interp, canvas, itemPtr, ob
 {
     TextItem *textPtr = (TextItem *) itemPtr;
     size_t length;
+    int length_int;
     int c;
     TkCanvas *canvasPtr = (TkCanvas *) canvas;
     Tk_CanvasTextInfo *textInfoPtr = textPtr->textInfoPtr;
@@ -1250,7 +1251,8 @@ GetTextIndex(interp, canvas, itemPtr, ob
 	goto doxy;
     }
 
-    string = Tcl_GetStringFromObj(obj, &length);
+    string = Tcl_GetStringFromObj(obj, &length_int);
+    length = (size_t)length_int;
     c = string[0];
     length = strlen(string);
 
