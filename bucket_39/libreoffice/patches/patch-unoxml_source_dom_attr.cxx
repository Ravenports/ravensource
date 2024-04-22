--- unoxml/source/dom/attr.cxx.orig	2024-03-22 19:34:51 UTC
+++ unoxml/source/dom/attr.cxx
@@ -30,6 +30,7 @@
 #include <com/sun/star/xml/dom/events/XMutationEvent.hpp>
 
 #include "document.hxx"
+#include <libxml/entities.h>
 
 using namespace css::uno;
 using namespace css::xml::dom;
