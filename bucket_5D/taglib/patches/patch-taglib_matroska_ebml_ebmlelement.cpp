--- taglib/matroska/ebml/ebmlelement.cpp.orig	2026-02-24 20:57:21 UTC
+++ taglib/matroska/ebml/ebmlelement.cpp
@@ -44,7 +44,7 @@ using namespace TagLib;
 std::unique_ptr<EBML::Element> EBML::Element::factory(File &file)
 {
   // Get the element ID
-  const offset_t offset = file.tell();
+  const TagLib::offset_t offset = file.tell();
   unsigned int uintId = readId(file);
   if(!uintId) {
     debug("Failed to parse EMBL ElementID");
@@ -151,12 +151,12 @@ unsigned int EBML::Element::readId(File
   return buffer.toUInt(true);
 }
 
-EBML::Element::Element(Id id, int sizeLength, offset_t dataSize):
+EBML::Element::Element(Id id, int sizeLength, TagLib::offset_t dataSize):
   id(id), sizeLength(sizeLength), dataSize(dataSize)
 {
 }
 
-EBML::Element::Element(Id id, int sizeLength, offset_t dataSize, offset_t):
+EBML::Element::Element(Id id, int sizeLength, TagLib::offset_t dataSize, TagLib::offset_t):
   id(id), sizeLength(sizeLength), dataSize(dataSize)
 {
 }
@@ -179,12 +179,12 @@ EBML::Element::Id EBML::Element::getId()
   return id;
 }
 
-offset_t EBML::Element::headSize() const
+TagLib::offset_t EBML::Element::headSize() const
 {
   return idSize(id) + sizeLength;
 }
 
-offset_t EBML::Element::getSize() const
+TagLib::offset_t EBML::Element::getSize() const
 {
   return headSize() + dataSize;
 }
