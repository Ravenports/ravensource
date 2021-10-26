$NetBSD: patch-t_libtap_tap.c,v 1.1 2018/09/29 12:54:16 tnn Exp $

don't redefine MAP_ANONYMOUS

--- t/libtap/tap.c.orig	2019-07-08 22:48:24 UTC
+++ t/libtap/tap.c
@@ -298,7 +298,7 @@ tap_end_todo () {
 #include <sys/param.h>
 #include <regex.h>
 
-#if defined __APPLE__ || defined BSD
+#if !defined(MAP_ANONYMOUS)
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
