$NetBSD: patch-charpool.cc,v 1.1 2023/06/09 12:53:14 adam Exp $

Fix build.

--- charpool.cc.orig	2024-02-28 18:46:45 UTC
+++ charpool.cc
@@ -62,6 +62,7 @@
 /* $Id: charpool.cc 38790 2024-02-28 18:46:45Z dmiller $ */
 
 #include <stddef.h>
+#include <limits.h>
 #undef NDEBUG
 #include <assert.h>
 
