$NetBSD: patch-store_source_storbase.hxx,v 1.2 2019/08/10 11:41:29 ryoon Exp $

include <cstdlib> for std::free()

--- store/source/storbase.hxx.orig	2025-01-12 19:04:12 UTC
+++ store/source/storbase.hxx
@@ -35,6 +35,7 @@
 #include <cstdlib>
 #include <memory>
 #include <utility>
+#include <cstdlib>
 
 /** @file store common internals.
 */
