--- unoxml/source/dom/attr.cxx.orig	2023-09-22 19:07:01 UTC
+++ unoxml/source/dom/attr.cxx
@@ -29,6 +29,7 @@
 #include <com/sun/star/xml/dom/events/XMutationEvent.hpp>
 
 #include "document.hxx"
+#include <libxml/entities.h>
 
 using namespace css::uno;
 using namespace css::xml::dom;
