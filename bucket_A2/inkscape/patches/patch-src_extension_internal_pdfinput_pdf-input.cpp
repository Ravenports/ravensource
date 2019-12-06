--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -689,12 +689,12 @@ PdfInput::open(::Inkscape::Extension::In
         //
         gchar const *poppler_datadir = g_getenv("POPPLER_DATADIR");
         if (poppler_datadir != NULL) {
-            globalParams = new GlobalParams(poppler_datadir);
+            globalParams = std::make_unique<GlobalParams>(poppler_datadir);
         } else {
-            globalParams = new GlobalParams();
+            globalParams = std::make_unique<GlobalParams>();
         }
 #else
-        globalParams = new GlobalParams();
+        globalParams = std::make_unique<GlobalParams>();
 #endif // ENABLE_OSX_APP_LOCATIONS
     }
 
