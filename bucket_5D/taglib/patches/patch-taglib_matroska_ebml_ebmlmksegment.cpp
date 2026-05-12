--- taglib/matroska/ebml/ebmlmksegment.cpp.orig	2026-05-09 07:46:20 UTC
+++ taglib/matroska/ebml/ebmlmksegment.cpp
@@ -34,8 +34,8 @@ namespace {
 
 template <EBML::Element::Id Id, typename ElementType>
 std::unique_ptr<ElementType> readElementAt(File &file,
-                                           offset_t offset,
-                                           offset_t maxOffset)
+                                           TagLib::offset_t offset,
+                                           TagLib::offset_t maxOffset)
 {
   if(offset < 0 || offset >= maxOffset) {
     return nullptr;
@@ -56,19 +56,19 @@ std::unique_ptr<ElementType> readElement
 
 } // namespace
 
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
@@ -78,11 +78,11 @@ bool EBML::MkSegment::read(File &file)
   return readLimited(file, dataSize);
 }
 
-bool EBML::MkSegment::readLimited(File &file, offset_t scanLimit)
+bool EBML::MkSegment::readLimited(File &file, TagLib::offset_t scanLimit)
 {
-  const offset_t filePos = file.tell();
-  const offset_t maxOffset = filePos + dataSize;
-  const offset_t maxScanOffset = filePos + std::min(scanLimit, dataSize);
+  const TagLib::offset_t filePos = file.tell();
+  const TagLib::offset_t maxOffset = filePos + dataSize;
+  const TagLib::offset_t maxScanOffset = filePos + std::min(scanLimit, dataSize);
   // When scanLimit is less than dataSize, the caller has requested a
   // fast/limited scan (e.g. AudioProperties::Fast).  In that case and if the
   // file has been opened in read-only mode, we skip parsing the Cues element,
@@ -90,7 +90,7 @@ bool EBML::MkSegment::readLimited(File &
   // network filesystems, and do not have to be updated in read-only mode.
   const bool skipCues = file.readOnly() && scanLimit < dataSize;
   MasterElement *pendingPaddingTarget = nullptr;
-  offset_t accumulatedPadding = 0;
+  TagLib::offset_t accumulatedPadding = 0;
   std::unique_ptr<Element> element;
   while((element = findNextElement(file, maxScanOffset))) {
     if(const Id id = element->getId(); id == Id::MkSeekHead) {
@@ -101,10 +101,10 @@ bool EBML::MkSegment::readLimited(File &
       if(const auto elementAfterSeekHead = findNextElement(file, maxScanOffset);
          elementAfterSeekHead && elementAfterSeekHead->getId() == Id::VoidElement)
         seekHead->setPadding(elementAfterSeekHead->getSize());
-      const offset_t segDataOffset = segmentDataOffset();
+      const TagLib::offset_t segDataOffset = segmentDataOffset();
       const auto matroskaSeekHead = parseSeekHead();
       const auto accumulateVoidPadding = [&](MasterElement *target) {
-        offset_t accPadding = 0;
+        TagLib::offset_t accPadding = 0;
         while(const auto next = findNextElement(file, maxOffset)) {
           if(next->getId() != Id::VoidElement)
             break;
@@ -121,7 +121,7 @@ bool EBML::MkSegment::readLimited(File &
       // which in turn lists Info / Tracks / Tags / Chapters / Attachments.
       // Follow such MkSeekHead -> MkSeekHead chains so the real entries are
       // not silently dropped.
-      List<std::pair<unsigned int, offset_t>> entries =
+      List<std::pair<unsigned int, TagLib::offset_t>> entries =
         matroskaSeekHead->entryList();
       // Guard against pathological / circular chains.
       int chainedSeekHeadsFollowed = 0;
@@ -129,7 +129,7 @@ bool EBML::MkSegment::readLimited(File &
 
       for(unsigned int i = 0; i < entries.size(); ++i) {
         const auto &[idValue, relativeOffset] = entries[i];
-        const offset_t absoluteOffset = segDataOffset + relativeOffset;
+        const TagLib::offset_t absoluteOffset = segDataOffset + relativeOffset;
         switch(static_cast<Id>(idValue)) {
         case Id::MkSeekHead: {
           if(chainedSeekHeadsFollowed++ >= MAX_CHAINED_SEEKHEADS)
