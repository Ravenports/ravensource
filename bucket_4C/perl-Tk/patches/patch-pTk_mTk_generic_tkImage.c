--- pTk/mTk/generic/tkImage.c.orig	2013-11-15 23:50:03 UTC
+++ pTk/mTk/generic/tkImage.c
@@ -1083,6 +1083,8 @@ int x;
 int y;
 int width;
 int height;
+int imgWidth;
+int imgHeight;
 {
     Tk_Tile tile = (Tk_Tile) clientData;
     Tk_TileChange *handler;
