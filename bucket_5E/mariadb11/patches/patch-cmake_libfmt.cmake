--- cmake/libfmt.cmake.orig	2024-08-05 08:49:38 UTC
+++ cmake/libfmt.cmake
@@ -15,7 +15,7 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL      "https://github.com/fmtlib/fmt/releases/download/11.0.1/fmt-11.0.1.zip"
+    URL      "file:///distfiles/fmt-11.0.1.zip"
     URL_MD5  5f3915e2eff60e7f70c558120592100d
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
