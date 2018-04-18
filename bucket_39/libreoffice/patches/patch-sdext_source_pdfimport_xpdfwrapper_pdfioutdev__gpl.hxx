--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2018-03-29 15:04:09 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -223,7 +223,6 @@ namespace pdfi
                               double dx, double dy,
                               double originX, double originY,
                               CharCode code, int nBytes, Unicode *u, int uLen) override;
-        virtual void drawString(GfxState *state, GooString *s) override;
         virtual void endTextObject(GfxState *state) override;
 
         //----- image drawing
