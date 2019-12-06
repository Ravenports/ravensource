--- sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx.orig	2019-09-18 14:12:06 UTC
+++ sdext/source/pdfimport/xpdfwrapper/wrapper_gpl.cxx
@@ -68,7 +68,7 @@ int main(int argc, char **argv)
     }
 
     // read config file
-    globalParams = new GlobalParams();
+    globalParams = std::make_unique<GlobalParams>();
     globalParams->setErrQuiet(true);
 #if defined(_MSC_VER)
     globalParams->setupBaseFonts(nullptr);
