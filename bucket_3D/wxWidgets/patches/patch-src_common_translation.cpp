--- src/common/translation.cpp.orig	2023-02-13 14:45:39 UTC
+++ src/common/translation.cpp
@@ -1409,7 +1409,7 @@ bool wxTranslations::AddStdCatalog()
     if ( AddCatalog("wxstd-" wxSTRINGIZE(wxMAJOR_VERSION) "." wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
-    if ( AddCatalog(wxS("wxstd")) )
+    if ( AddCatalog(wxS("wxstd") wxSTRINGIZE(wxMAJOR_VERSION) wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
     return false;
