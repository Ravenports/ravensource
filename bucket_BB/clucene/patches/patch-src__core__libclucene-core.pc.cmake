--- src/core/libclucene-core.pc.cmake.orig	2011-03-17 00:21:07 UTC
+++ src/core/libclucene-core.pc.cmake
@@ -6,6 +6,6 @@ includedir=${prefix}/include:${prefix}/i
 Name: libclucene
 Description: CLucene - a C++ search engine, ported from the popular Apache Lucene
 Version: @CLUCENE_VERSION_MAJOR@.@CLUCENE_VERSION_MINOR@.@CLUCENE_VERSION_REVISION@.@CLUCENE_VERSION_PATCH@
-Libs: -L${prefix}/@LIB_DESTINATION@/ -lclucene-core
+Libs: -L${prefix}/@LIB_DESTINATION@/ -lclucene-core -lclucene-shared
 Cflags: -I${prefix}/include -I${prefix}/include/CLucene/ext
 ~
