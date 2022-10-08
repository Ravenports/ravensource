--- src/common/translation.cpp.orig	2022-09-05 18:36:11 UTC
+++ src/common/translation.cpp
@@ -1409,7 +1409,7 @@ bool wxTranslations::AddStdCatalog()
     if ( AddCatalog("wxstd-" wxSTRINGIZE(wxMAJOR_VERSION) "." wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
-    if ( AddCatalog(wxS("wxstd")) )
+    if ( AddCatalog(wxS("wxstd") wxSTRINGIZE(wxMAJOR_VERSION) wxSTRINGIZE(wxMINOR_VERSION)) )
         return true;
 
     return false;
