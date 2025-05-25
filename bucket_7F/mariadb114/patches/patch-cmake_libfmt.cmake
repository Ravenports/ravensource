--- cmake/libfmt.cmake.orig	2025-05-19 16:36:43 UTC
+++ cmake/libfmt.cmake
@@ -15,7 +15,7 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL "https://github.com/fmtlib/fmt/releases/download/11.1.4/fmt-11.1.4.zip"
+    URL "file:///distfiles/fmt-11.1.4.zip"
     URL_MD5 ad6a56b15cddf4aad2a234e7cfc9e8c9
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
