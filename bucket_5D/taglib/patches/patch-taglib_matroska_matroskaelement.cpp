--- taglib/matroska/matroskaelement.cpp.orig	2026-07-05 08:55:01 UTC
+++ taglib/matroska/matroskaelement.cpp
@@ -34,8 +34,8 @@ public:
   ~ElementPrivate() = default;
   ElementPrivate(const ElementPrivate &) = delete;
   ElementPrivate &operator=(const ElementPrivate &) = delete;
-  offset_t size = 0;
-  offset_t offset = 0;
+  TagLib::offset_t size = 0;
+  TagLib::offset_t offset = 0;
   ID id = 0;
   ByteVector data;
   List<Element *> sizeListeners;
@@ -61,12 +61,12 @@ Matroska::Element::Element(ID id) :
 
 Matroska::Element::~Element() = default;
 
-offset_t Matroska::Element::size() const
+TagLib::offset_t Matroska::Element::size() const
 {
   return e->size;
 }
 
-offset_t Matroska::Element::offset() const
+TagLib::offset_t Matroska::Element::offset() const
 {
   return e->offset;
 }
@@ -81,17 +81,17 @@ const ByteVector &Matroska::Element::dat
   return e->data;
 }
 
-void Matroska::Element::setOffset(offset_t offset)
+void Matroska::Element::setOffset(TagLib::offset_t offset)
 {
   e->offset = offset;
 }
 
-void Matroska::Element::adjustOffset(offset_t delta)
+void Matroska::Element::adjustOffset(TagLib::offset_t delta)
 {
   e->offset += delta;
 }
 
-void Matroska::Element::setSize(offset_t size)
+void Matroska::Element::setSize(TagLib::offset_t size)
 {
   e->size = size;
 }
@@ -165,7 +165,7 @@ bool Matroska::Element::needsRender() co
   return e->needsRender;
 }
 
-bool Matroska::Element::emitSizeChanged(offset_t delta)
+bool Matroska::Element::emitSizeChanged(TagLib::offset_t delta)
 {
   for(const auto element : e->sizeListeners) {
     if(!element->sizeChanged(*this, delta))
@@ -174,7 +174,7 @@ bool Matroska::Element::emitSizeChanged(
   return true;
 }
 
-bool Matroska::Element::sizeChanged(Element &caller, offset_t delta)
+bool Matroska::Element::sizeChanged(Element &caller, TagLib::offset_t delta)
 {
   // The equal case is needed when multiple new elements are added
   // (e.g. Attachments and Tags), they will start with the same offset
@@ -185,9 +185,9 @@ bool Matroska::Element::sizeChanged(Elem
   return true;
 }
 
-offset_t Matroska::Element::sizeRenderedOrWritten() const
+TagLib::offset_t Matroska::Element::sizeRenderedOrWritten() const
 {
-  const offset_t dataSize = e->data.size();
+  const TagLib::offset_t dataSize = e->data.size();
   return dataSize != 0 ? dataSize : e->size;
 }
 
