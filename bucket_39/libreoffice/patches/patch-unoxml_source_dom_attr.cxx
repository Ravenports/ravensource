--- unoxml/source/dom/attr.cxx.orig	2026-04-09 16:07:27 UTC
+++ unoxml/source/dom/attr.cxx
@@ -30,6 +30,7 @@
 #include <com/sun/star/xml/dom/events/XMutationEvent.hpp>
 
 #include "document.hxx"
+#include <libxml/entities.h>
 
 using namespace css::uno;
 using namespace css::xml::dom;
