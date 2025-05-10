$NetBSD: patch-charpool.cc,v 1.1 2023/06/09 12:53:14 adam Exp $

Fix build.

--- charpool.cc.orig	2025-02-26 17:44:43 UTC
+++ charpool.cc
@@ -62,6 +62,7 @@
 /* $Id: charpool.cc 39083 2025-02-26 17:44:43Z dmiller $ */
 
 #include <stddef.h>
+#include <limits.h>
 #undef NDEBUG
 #include <assert.h>
 
