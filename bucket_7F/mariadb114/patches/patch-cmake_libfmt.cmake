--- cmake/libfmt.cmake.orig	2025-11-04 12:57:48 UTC
+++ cmake/libfmt.cmake
@@ -15,7 +15,7 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL "https://github.com/fmtlib/fmt/releases/download/12.0.0/fmt-12.0.0.zip"
+    URL "file:///distfiles/fmt-12.0.0.zip"
     URL_MD5 9bd04e6e8c5b1733e4eefb473604219d
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
