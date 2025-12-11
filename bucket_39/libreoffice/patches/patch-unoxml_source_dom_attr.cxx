--- unoxml/source/dom/attr.cxx.orig	2025-12-01 19:30:03 UTC
+++ unoxml/source/dom/attr.cxx
@@ -30,6 +30,7 @@
 #include <com/sun/star/xml/dom/events/XMutationEvent.hpp>
 
 #include "document.hxx"
+#include <libxml/entities.h>
 
 using namespace css::uno;
 using namespace css::xml::dom;
