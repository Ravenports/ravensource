--- cmake/libfmt.cmake.orig	2023-08-11 10:53:11 UTC
+++ cmake/libfmt.cmake
@@ -15,8 +15,8 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL      "https://github.com/fmtlib/fmt/archive/refs/tags/8.0.1.zip"
-    URL_MD5  e77873199e897ca9f780479ad68e25b1
+    URL      "file:///distfiles/fmtlib-fmt-8.0.1.tar.gz"
+    URL_MD5  7d5af964c6633ef90cd6a47be3afe6a0
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
     BUILD_COMMAND ""
