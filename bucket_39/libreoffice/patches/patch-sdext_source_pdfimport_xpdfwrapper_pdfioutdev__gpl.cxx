--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2019-09-18 14:12:06 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -491,12 +491,12 @@ void PDFOutDev::writeFontFile( GfxFont*
     gfree(pBuf);
 }
 
-void PDFOutDev::printPath( GfxPath* pPath )
+void PDFOutDev::printPath( const GfxPath* pPath )
 {
     int nSubPaths = pPath ? pPath->getNumSubpaths() : 0;
     for( int i=0; i<nSubPaths; i++ )
     {
-        GfxSubpath* pSub  = pPath->getSubpath( i );
+        const GfxSubpath* pSub  = pPath->getSubpath( i );
         const int nPoints = pSub->getNumPoints();
 
         printf( " subpath %d", pSub->isClosed() );
