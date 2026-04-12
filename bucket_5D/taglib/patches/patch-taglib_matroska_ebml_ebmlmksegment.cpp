--- taglib/matroska/ebml/ebmlmksegment.cpp.orig	2026-01-25 11:41:46 UTC
+++ taglib/matroska/ebml/ebmlmksegment.cpp
@@ -30,26 +30,26 @@
 
 using namespace TagLib;
 
-EBML::MkSegment::MkSegment(int sizeLength, offset_t dataSize, offset_t offset):
+EBML::MkSegment::MkSegment(int sizeLength, TagLib::offset_t dataSize, TagLib::offset_t offset):
   MasterElement(Id::MkSegment, sizeLength, dataSize, offset)
 {
 }
 
-EBML::MkSegment::MkSegment(Id, int sizeLength, offset_t dataSize, offset_t offset):
+EBML::MkSegment::MkSegment(Id, int sizeLength, TagLib::offset_t dataSize, TagLib::offset_t offset):
   MasterElement(Id::MkSegment, sizeLength, dataSize, offset)
 {
 }
 
 EBML::MkSegment::~MkSegment() = default;
 
-offset_t EBML::MkSegment::segmentDataOffset() const
+TagLib::offset_t EBML::MkSegment::segmentDataOffset() const
 {
   return offset + idSize(id) + sizeLength;
 }
 
 bool EBML::MkSegment::read(File &file)
 {
-  const offset_t maxOffset = file.tell() + dataSize;
+  const TagLib::offset_t maxOffset = file.tell() + dataSize;
   std::unique_ptr<Element> element;
   int i = 0;
   int seekHeadIndex = -1;
