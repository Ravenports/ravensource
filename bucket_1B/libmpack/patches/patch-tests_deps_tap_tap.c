$NetBSD$

Fix redefinition of MAP_ANONYMOUS
https://github.com/libmpack/libmpack/issues/42

--- test/deps/tap/tap.c.orig	2017-03-19 20:48:19 UTC
+++ test/deps/tap/tap.c
@@ -298,8 +298,12 @@ tap_end_todo () {
 #include <sys/param.h>
 #include <regex.h>
 
-#if defined __APPLE__ || defined BSD
+#ifndef MAP_ANONYMOUS
+#ifdef MAP_ANON
 #define MAP_ANONYMOUS MAP_ANON
+#else
+#error "System does not support mapping anonymous pages"
+#endif
 #endif
 
 /* Create a shared memory int to keep track of whether a piece of code executed
