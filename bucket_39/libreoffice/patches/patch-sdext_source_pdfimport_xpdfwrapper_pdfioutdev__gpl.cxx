--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2018-03-29 15:04:09 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -446,7 +446,7 @@ int PDFOutDev::parseFont( long long nNew
     FontAttributes aNewFont;
     int nSize = 0;
 
-    GooString* pFamily = gfxFont->getName();
+    const GooString* pFamily = gfxFont->getName();
     if( pFamily )
     {
         aNewFont.familyName.clear();
@@ -742,7 +742,7 @@ void PDFOutDev::updateFont(GfxState *sta
         FontAttributes aFont;
         int nEmbedSize=0;
 
-        Ref* pID = gfxFont->getID();
+        const Ref* pID = gfxFont->getID();
         // TODO(Q3): Portability problem
         long long fontID = (long long)pID->gen << 32 | (long long)pID->num;
         std::unordered_map< long long, FontAttributes >::const_iterator it =
@@ -932,11 +932,6 @@ void PDFOutDev::drawChar(GfxState *state
     printf( "\n" );
 }
 
-void PDFOutDev::drawString(GfxState*, GooString* /*s*/)
-{
-    // TODO(F3): NYI
-}
-
 void PDFOutDev::endTextObject(GfxState*)
 {
     printf( "endTextObject\n" );
