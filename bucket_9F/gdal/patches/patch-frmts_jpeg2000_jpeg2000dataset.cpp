--- frmts/jpeg2000/jpeg2000dataset.cpp.orig	2020-07-07 11:46:27 UTC
+++ frmts/jpeg2000/jpeg2000dataset.cpp
@@ -595,7 +595,7 @@ GDALDataset *JPEG2000Dataset::Open( GDAL
 
 {
     int         iFormat;
-    char        *pszFormatName = nullptr;
+    const char        *pszFormatName = nullptr;
 
     if (!Identify(poOpenInfo))
         return nullptr;
