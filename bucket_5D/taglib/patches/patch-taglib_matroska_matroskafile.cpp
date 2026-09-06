--- taglib/matroska/matroskafile.cpp.orig	2026-07-05 08:55:01 UTC
+++ taglib/matroska/matroskafile.cpp
@@ -147,7 +147,7 @@ PropertyMap Matroska::File::setPropertie
 
 namespace {
 
-  constexpr offset_t FAST_SCAN_LIMIT = static_cast<offset_t>(512 * 1024);
+  constexpr TagLib::offset_t FAST_SCAN_LIMIT = static_cast<TagLib::offset_t>(512 * 1024);
 
   String keyForAttachedFile(const Matroska::AttachedFile &attachedFile)
   {
@@ -364,7 +364,7 @@ Matroska::Chapters *Matroska::File::chap
 
 void Matroska::File::read(bool readProperties, Properties::ReadStyle readStyle)
 {
-  const offset_t fileLength = length();
+  const TagLib::offset_t fileLength = length();
 
   // Find the EBML Header
   const auto head = EBML::element_cast<EBML::Element::Id::EBMLHeader>(
@@ -381,7 +381,7 @@ void Matroska::File::read(bool readPrope
     head->skipData(*this);
   }
 
-  offset_t maxOffset = fileLength;
+  TagLib::offset_t maxOffset = fileLength;
   if (readStyle == Properties::ReadStyle::Fast && maxOffset > FAST_SCAN_LIMIT) {
     maxOffset = FAST_SCAN_LIMIT;
   }
@@ -539,9 +539,9 @@ bool Matroska::File::save(WriteStyle wri
     // (Cues are always after the last Cluster). A value of 0 means
     // "no boundary" – any offset compares >= 0, so the boundary check is
     // a no-op in non-AvoidInsert modes.
-    offset_t audioBoundary = 0;
+    TagLib::offset_t audioBoundary = 0;
     if(writeStyle == WriteStyle::AvoidInsert && d->cues) {
-      const offset_t segDataOffset = d->segment->dataOffset();
+      const TagLib::offset_t segDataOffset = d->segment->dataOffset();
       for(const auto &cp : d->cues->cuePointList()) {
         for(const auto &ct : cp->cueTrackList()) {
           audioBoundary = std::max(audioBoundary,
@@ -569,7 +569,7 @@ bool Matroska::File::save(WriteStyle wri
     // so a trailing void would be wasted space.
     if(writeStyle == WriteStyle::AvoidInsert) {
       Element *trailing = nullptr;
-      offset_t maxOffset = 0;
+      TagLib::offset_t maxOffset = 0;
       const auto consider = [&](Element *e) {
         if(e && e->size() > 0 && e->offset() > maxOffset) {
           maxOffset = e->offset();
@@ -633,7 +633,7 @@ bool Matroska::File::save(WriteStyle wri
     rendering = false;
     // Initialize appendOffset for AvoidInsert elements at the start of each round.
     if(writeStyle == WriteStyle::AvoidInsert) {
-      const offset_t appendOffset = d->segment->endOffset();
+      const TagLib::offset_t appendOffset = d->segment->endOffset();
       for(const auto element : renderList)
         element->setAppendOffset(appendOffset);
     }
@@ -655,20 +655,20 @@ bool Matroska::File::save(WriteStyle wri
     // Collect moved elements in render order (= ascending original-offset order
     // = order they appear in renderList before any re-sort).
     List<Element *> movedElements;
-    offset_t totalMovedSize = 0;
+    TagLib::offset_t totalMovedSize = 0;
     for(const auto element : renderList) {
       if(element->wasMoved()) {
         movedElements.append(element);
-        totalMovedSize += static_cast<offset_t>(element->data().size());
+        totalMovedSize += static_cast<TagLib::offset_t>(element->data().size());
       }
     }
     if(!movedElements.isEmpty()) {
       // The segment end includes in-place growths AND all moved element sizes.
       // The moved elements start right after all in-place content.
-      offset_t appendAt = d->segment->endOffset() - totalMovedSize;
+      TagLib::offset_t appendAt = d->segment->endOffset() - totalMovedSize;
       for(const auto element : movedElements) {
         element->setOffset(appendAt);
-        appendAt += static_cast<offset_t>(element->data().size());
+        appendAt += static_cast<TagLib::offset_t>(element->data().size());
       }
     }
   }
@@ -676,7 +676,7 @@ bool Matroska::File::save(WriteStyle wri
   // For elements that were moved to the end by AvoidInsert, update their
   // seek head entry to reflect the new file position.
   if(writeStyle == WriteStyle::AvoidInsert && d->seekHead) {
-    const offset_t segDataOffset = d->segment->dataOffset();
+    const TagLib::offset_t segDataOffset = d->segment->dataOffset();
     for(const auto element : renderList) {
       if(element->wasMoved()) {
         d->seekHead->updateEntry(element->id(), element->offset() - segDataOffset);
