--- unoxml/source/dom/entity.hxx.orig	2025-01-23 21:25:49 UTC
+++ unoxml/source/dom/entity.hxx
@@ -19,6 +19,7 @@
 
 #pragma once
 
+#include <libxml/entities.h>
 #include <libxml/tree.h>
 
 #include <sal/types.h>
