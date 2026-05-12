--- taglib/matroska/ebml/ebmlmasterelement.cpp.orig	2026-05-04 14:43:04 UTC
+++ taglib/matroska/ebml/ebmlmasterelement.cpp
@@ -26,7 +26,7 @@
 
 using namespace TagLib;
 
-EBML::MasterElement::MasterElement(Id id, int sizeLength, offset_t dataSize, offset_t offset):
+EBML::MasterElement::MasterElement(Id id, int sizeLength, TagLib::offset_t dataSize, TagLib::offset_t offset):
   Element(id, sizeLength, dataSize), offset(offset)
 {
 }
@@ -38,7 +38,7 @@ EBML::MasterElement::MasterElement(Id id
 
 EBML::MasterElement::~MasterElement() = default;
 
-offset_t EBML::MasterElement::getOffset() const
+TagLib::offset_t EBML::MasterElement::getOffset() const
 {
   return offset;
 }
@@ -78,22 +78,22 @@ std::list<std::unique_ptr<EBML::Element>
   return elements.cend();
 }
 
-offset_t EBML::MasterElement::getPadding() const
+TagLib::offset_t EBML::MasterElement::getPadding() const
 {
   return padding;
 }
 
-void EBML::MasterElement::setPadding(offset_t numBytes)
+void EBML::MasterElement::setPadding(TagLib::offset_t numBytes)
 {
   padding = numBytes;
 }
 
-offset_t EBML::MasterElement::getMinRenderSize() const
+TagLib::offset_t EBML::MasterElement::getMinRenderSize() const
 {
   return minRenderSize;
 }
 
-void EBML::MasterElement::setMinRenderSize(offset_t minimumSize)
+void EBML::MasterElement::setMinRenderSize(TagLib::offset_t minimumSize)
 {
   minRenderSize = minimumSize;
 }
@@ -105,7 +105,7 @@ bool EBML::MasterElement::read(File &fil
     debug("EBML: Maximum nesting depth exceeded");
     return false;
   }
-  const offset_t maxOffset = file.tell() + dataSize;
+  const TagLib::offset_t maxOffset = file.tell() + dataSize;
   std::unique_ptr<Element> element;
   while((element = findNextElement(file, maxOffset))) {
     if(auto master = dynamic_cast<MasterElement *>(element.get())) {
