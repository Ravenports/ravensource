--- cmake/libfmt.cmake.orig	2026-08-23 18:06:59.066513000 +0200
+++ cmake/libfmt.cmake	2026-08-23 18:07:50.707770000 +0200
@@ -15,10 +15,10 @@
   IF(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
     # it's for RHEL-7, gcc 4.8.5
     # with newer fmt it complains about missing space in operator""_a()
-    SET(source URL "https://github.com/fmtlib/fmt/releases/download/11.0.2/fmt-11.0.2.zip"
+    SET(source URL "file:///distfiles/fmt-12.1.0.zip"
                URL_MD5 c622dca45ec3fc95254c48370a9f7a1d)
   ELSE()
-    SET(source URL "https://github.com/fmtlib/fmt/releases/download/12.2.0/fmt-12.2.0.zip"
+    SET(source URL "file:///distfiles/fmt-12.2.0.zip"
                URL_MD5 6083253772ad29e73a4d5920be08918e)
   ENDIF()
 
