$NetBSD: patch-charpool.cc,v 1.1 2023/06/09 12:53:14 adam Exp $

Fix build.

--- charpool.cc.orig	2026-10-23 13:39:29 UTC
+++ charpool.cc
@@ -62,6 +62,7 @@
 /* $Id$ */
 
 #include <stddef.h>
+#include <limits.h>
 #undef NDEBUG
 #include <assert.h>
 #include <climits>
