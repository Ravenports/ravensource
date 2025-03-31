--- unoxml/source/dom/document.cxx.orig	2025-03-21 15:34:31 UTC
+++ unoxml/source/dom/document.cxx
@@ -33,6 +33,7 @@
 #include "domimplementation.hxx"
 #include "entity.hxx"
 #include "notation.hxx"
+#include <libxml/xmlIO.h>
 
 #include <event.hxx>
 #include <mutationevent.hxx>
