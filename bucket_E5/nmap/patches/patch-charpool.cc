$NetBSD: patch-charpool.cc,v 1.1 2023/06/09 12:53:14 adam Exp $

Fix build.

--- charpool.cc.orig	2026-08-05 21:12:13 UTC
+++ charpool.cc
@@ -62,6 +62,7 @@
 /* $Id$ */
 
 #include <stddef.h>
+#include <limits.h>
 #undef NDEBUG
 #include <assert.h>
 #include <climits>
