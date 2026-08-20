--- taglib/matroska/matroskaseekhead.cpp.orig	2026-05-17 12:40:31 UTC
+++ taglib/matroska/matroskaseekhead.cpp
@@ -32,7 +32,7 @@
 
 using namespace TagLib;
 
-Matroska::SeekHead::SeekHead(offset_t segmentDataOffset) :
+Matroska::SeekHead::SeekHead(TagLib::offset_t segmentDataOffset) :
   Element(static_cast<ID>(EBML::Element::Id::MkSeekHead)),
   segmentDataOffset(segmentDataOffset)
 {
@@ -60,7 +60,7 @@ void Matroska::SeekHead::addEntry(const
   setNeedsRender(true);
 }
 
-void Matroska::SeekHead::addEntry(ID id, offset_t offset)
+void Matroska::SeekHead::addEntry(ID id, TagLib::offset_t offset)
 {
   entries.append({id, offset});
   setNeedsRender(true);
@@ -113,7 +113,7 @@ void Matroska::SeekHead::sort()
   entries.sort([](const auto &a, const auto &b) { return a.second < b.second; });
 }
 
-bool Matroska::SeekHead::sizeChanged(Element &caller, offset_t delta)
+bool Matroska::SeekHead::sizeChanged(Element &caller, TagLib::offset_t delta)
 {
   ID callerID = caller.id();
   if(callerID == static_cast<ID>(EBML::Element::Id::MkSegment)) {
@@ -123,7 +123,7 @@ bool Matroska::SeekHead::sizeChanged(Ele
   // The equal case is needed when multiple new elements are added
   // (e.g. Attachments and Tags), they will start with the same offset
   // and are updated via size change handling.
-  offset_t offset = caller.offset() - segmentDataOffset;
+  TagLib::offset_t offset = caller.offset() - segmentDataOffset;
   auto it = entries.begin();
   while(it != entries.end()) {
     it = std::find_if(it,
