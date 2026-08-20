--- taglib/matroska/ebml/ebmlvoidelement.cpp.orig	2026-05-17 12:40:31 UTC
+++ taglib/matroska/ebml/ebmlvoidelement.cpp
@@ -27,12 +27,12 @@
 
 using namespace TagLib;
 
-EBML::VoidElement::VoidElement(int sizeLength, offset_t dataSize):
+EBML::VoidElement::VoidElement(int sizeLength, TagLib::offset_t dataSize):
   Element(Id::VoidElement, sizeLength, dataSize)
 {
 }
 
-EBML::VoidElement::VoidElement(Id, int sizeLength, offset_t dataSize, offset_t):
+EBML::VoidElement::VoidElement(Id, int sizeLength, TagLib::offset_t dataSize, TagLib::offset_t):
   Element(Id::VoidElement, sizeLength, dataSize)
 {
 }
@@ -44,10 +44,10 @@ EBML::VoidElement::VoidElement():
 
 ByteVector EBML::VoidElement::render()
 {
-  offset_t bytesNeeded = targetSize;
+  TagLib::offset_t bytesNeeded = targetSize;
   ByteVector buffer = renderId();
   bytesNeeded -= buffer.size();
-  sizeLength = static_cast<int>(std::min(bytesNeeded, static_cast<offset_t>(8)));
+  sizeLength = static_cast<int>(std::min(bytesNeeded, static_cast<TagLib::offset_t>(8)));
   bytesNeeded -= sizeLength;
   dataSize = bytesNeeded;
   buffer.append(renderVINT(dataSize, sizeLength));
@@ -57,17 +57,17 @@ ByteVector EBML::VoidElement::render()
   return buffer;
 }
 
-offset_t EBML::VoidElement::getTargetSize() const
+TagLib::offset_t EBML::VoidElement::getTargetSize() const
 {
   return targetSize;
 }
 
-void EBML::VoidElement::setTargetSize(offset_t size)
+void EBML::VoidElement::setTargetSize(TagLib::offset_t size)
 {
   this->targetSize = std::max(size, MIN_VOID_ELEMENT_SIZE);
 }
 
-ByteVector EBML::VoidElement::renderSize(offset_t targetSize)
+ByteVector EBML::VoidElement::renderSize(TagLib::offset_t targetSize)
 {
   VoidElement element;
   element.setTargetSize(targetSize);
