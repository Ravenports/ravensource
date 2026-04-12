--- taglib/matroska/matroskasegment.cpp.orig	2026-01-25 11:41:46 UTC
+++ taglib/matroska/matroskasegment.cpp
@@ -24,7 +24,7 @@
 
 using namespace TagLib;
 
-Matroska::Segment::Segment(offset_t sizeLength, offset_t dataSize, offset_t lengthOffset) :
+Matroska::Segment::Segment(TagLib::offset_t sizeLength, TagLib::offset_t dataSize, TagLib::offset_t lengthOffset) :
   Element(static_cast<ID>(EBML::Element::Id::MkSegment)),
   sizeLength(sizeLength), dataSize(dataSize)
 {
@@ -58,14 +58,14 @@ bool Matroska::Segment::render()
   return true;
 }
 
-bool Matroska::Segment::sizeChanged(Element &, offset_t delta)
+bool Matroska::Segment::sizeChanged(Element &, TagLib::offset_t delta)
 {
   dataSize += delta;
   setNeedsRender(true);
   return true;
 }
 
-offset_t Matroska::Segment::dataOffset() const
+TagLib::offset_t Matroska::Segment::dataOffset() const
 {
   return offset() + sizeLength;
 }
