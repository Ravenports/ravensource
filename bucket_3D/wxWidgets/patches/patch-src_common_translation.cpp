--- src/common/translation.cpp.orig	2024-05-13 16:22:43 UTC
+++ src/common/translation.cpp
@@ -1409,7 +1409,7 @@ bool wxTranslations::AddStdCatalog()
     if ( AddAvailableCatalog("wxstd-" wxSTRINGIZE(wxMAJOR_VERSION) "." wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
-    if ( AddCatalog(wxS("wxstd")) )
+    if ( AddCatalog(wxS("wxstd") wxSTRINGIZE(wxMAJOR_VERSION) wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
     return false;
