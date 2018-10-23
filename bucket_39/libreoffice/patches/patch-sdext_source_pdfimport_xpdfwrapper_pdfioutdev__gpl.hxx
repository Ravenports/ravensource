--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2018-10-03 19:01:39 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -165,7 +165,7 @@ namespace pdfi
         //----- initialization and control
 
         // Set default transform matrix.
-        virtual void setDefaultCTM(double *ctm) override;
+        virtual void setDefaultCTM(double *ctm);
 
         // Start a page.
         virtual void startPage(int pageNum, GfxState *state
