$NetBSD: patch-charpool.cc,v 1.1 2023/06/09 12:53:14 adam Exp $

Fix build.

--- charpool.cc.orig	2023-04-14 17:11:46 UTC
+++ charpool.cc
@@ -61,6 +61,7 @@
 /* $Id: charpool.cc 38653 2023-04-14 17:11:46Z dmiller $ */
 
 #include <stddef.h>
+#include <limits.h>
 #undef NDEBUG
 #include <assert.h>
 
