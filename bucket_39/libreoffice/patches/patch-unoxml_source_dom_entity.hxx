--- unoxml/source/dom/entity.hxx.orig	2026-01-14 23:16:14 UTC
+++ unoxml/source/dom/entity.hxx
@@ -19,6 +19,7 @@
 
 #pragma once
 
+#include <libxml/entities.h>
 #include <libxml/tree.h>
 
 #include <sal/types.h>
