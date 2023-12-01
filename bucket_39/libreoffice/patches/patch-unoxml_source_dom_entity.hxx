--- unoxml/source/dom/entity.hxx.orig	2023-09-22 19:07:01 UTC
+++ unoxml/source/dom/entity.hxx
@@ -19,6 +19,7 @@
 
 #pragma once
 
+#include <libxml/entities.h>
 #include <libxml/tree.h>
 
 #include <sal/types.h>
