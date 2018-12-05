--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2018-10-30 16:55:21 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -528,7 +528,7 @@ void PDFOutDev::printPath( GfxPath* pPat
 PDFOutDev::PDFOutDev( PDFDoc* pDoc ) :
     m_pDoc( pDoc ),
     m_aFontMap(),
-    m_pUtf8Map( new UnicodeMap("UTF-8", gTrue, &mapUTF8) ),
+    m_pUtf8Map( new UnicodeMap("UTF-8", true, &mapUTF8) ),
     m_bSkipImages(false)
 {
 }
@@ -953,11 +953,11 @@ void PDFOutDev::endTextObject(GfxState*)
 }
 
 void PDFOutDev::drawImageMask(GfxState* pState, Object*, Stream* str,
-                              int width, int height, GBool invert,
+                              int width, int height, bool invert,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                              GBool /*interpolate*/,
+                              bool /*interpolate*/,
 #endif
-                              GBool /*inlineImg*/ )
+                              bool /*inlineImg*/ )
 {
     if (m_bSkipImages)
         return;
@@ -986,9 +986,9 @@ void PDFOutDev::drawImageMask(GfxState*
 void PDFOutDev::drawImage(GfxState*, Object*, Stream* str,
                           int width, int height, GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                          GBool /*interpolate*/,
+                          bool /*interpolate*/,
 #endif
-                          int* maskColors, GBool /*inlineImg*/ )
+                          int* maskColors, bool /*inlineImg*/ )
 {
     if (m_bSkipImages)
         return;
@@ -1037,13 +1037,13 @@ void PDFOutDev::drawMaskedImage(GfxState
                                 int width, int height,
                                 GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                GBool /*interpolate*/,
+                                bool /*interpolate*/,
 #endif
                                 Stream* maskStr,
                                 int maskWidth, int maskHeight,
-                                GBool maskInvert
+                                bool maskInvert
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                , GBool /*maskInterpolate*/
+                                , bool /*maskInterpolate*/
 #endif
                                )
 {
@@ -1059,13 +1059,13 @@ void PDFOutDev::drawSoftMaskedImage(GfxS
                                     int width, int height,
                                     GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                    GBool /*interpolate*/,
+                                    bool /*interpolate*/,
 #endif
                                     Stream* maskStr,
                                     int maskWidth, int maskHeight,
                                     GfxImageColorMap* maskColorMap
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                    , GBool /*maskInterpolate*/
+                                    , bool /*maskInterpolate*/
 #endif
                                    )
 {
