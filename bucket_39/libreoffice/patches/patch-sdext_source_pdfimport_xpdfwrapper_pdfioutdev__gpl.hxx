--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2019-09-18 14:12:06 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -149,7 +149,7 @@ namespace pdfi
 
         int  parseFont( long long nNewId, GfxFont* pFont, GfxState* state ) const;
         void writeFontFile( GfxFont* gfxFont ) const;
-        static void printPath( GfxPath* pPath );
+        static void printPath( const GfxPath* pPath );
 
     public:
         explicit PDFOutDev( PDFDoc* pDoc );
@@ -235,7 +235,7 @@ namespace pdfi
         virtual void drawChar(GfxState *state, double x, double y,
                               double dx, double dy,
                               double originX, double originY,
-                              CharCode code, int nBytes, Unicode *u, int uLen) override;
+                              CharCode code, int nBytes, Unicode *u, int uLen);
 #if POPPLER_CHECK_VERSION(0, 64, 0)
         virtual void drawString(GfxState *state, const GooString *s) override;
 #else
@@ -251,7 +251,7 @@ namespace pdfi
         virtual void drawImage(GfxState *state, Object *ref, Stream *str,
                                int width, int height, GfxImageColorMap *colorMap,
                                poppler_bool interpolate,
-                               int* maskColors, poppler_bool inlineImg) override;
+                               int* maskColors, poppler_bool inlineImg);
         virtual void drawMaskedImage(GfxState *state, Object *ref, Stream *str,
                                      int width, int height,
                                      GfxImageColorMap *colorMap,
