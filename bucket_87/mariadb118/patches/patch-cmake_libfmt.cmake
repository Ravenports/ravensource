--- cmake/libfmt.cmake.orig	2026-01-31 13:27:46 UTC
+++ cmake/libfmt.cmake
@@ -15,7 +15,7 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL "https://github.com/fmtlib/fmt/releases/download/12.1.0/fmt-12.1.0.zip"
+    URL "file:///distfiles/fmt-12.1.0.zip"
     URL_MD5 028c6979cad96a4260154f091885171a
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
