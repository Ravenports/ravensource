--- taglib/mp4/mp4qtchapterlist.cpp.orig	2026-07-17 03:23:37 UTC
+++ taglib/mp4/mp4qtchapterlist.cpp
@@ -57,7 +57,7 @@ namespace
   // -- Parent / offset fixup (mirrors mp4chapterlist.cpp) -------------------
 
   void updateParentSizes(TagLib::File *file, const MP4::AtomList &path,
-                         offset_t delta, int ignore = 0)
+                         TagLib::offset_t delta, int ignore = 0)
   {
     if(static_cast<int>(path.size()) <= ignore)
       return;
@@ -81,7 +81,7 @@ namespace
   }
 
   void updateChunkOffsets(TagLib::File *file, const MP4::Atoms *atoms,
-                          offset_t delta, offset_t offset)
+                          TagLib::offset_t delta, TagLib::offset_t offset)
   {
     if(const MP4::Atom *moov = atoms->find("moov")) {
       const MP4::AtomList stco = moov->findall("stco", true);
@@ -95,7 +95,7 @@ namespace
         unsigned int pos = 4;
         const unsigned int maxPos = data.size() - 4;
         while(count-- && pos <= maxPos) {
-          auto o = static_cast<offset_t>(data.toUInt(pos));
+          auto o = static_cast<TagLib::offset_t>(data.toUInt(pos));
           if(o > offset)
             o += delta;
           file->writeBlock(ByteVector::fromUInt(static_cast<unsigned int>(o)));
@@ -296,10 +296,10 @@ namespace
     for(const auto &child : audioTrak->children()) {
       if(child->name() == "tref") {
         file->seek(child->offset() + 8);
-        const offset_t trefEnd = child->offset() + child->length();
+        const TagLib::offset_t trefEnd = child->offset() + child->length();
 
         while(file->tell() + 8 <= trefEnd) {
-          const offset_t boxStart = file->tell();
+          const TagLib::offset_t boxStart = file->tell();
           ByteVector header = file->readBlock(8);
           if(header.size() < 8)
             break;
@@ -529,7 +529,7 @@ namespace
                               long long durationMs,
                               const MP4::ChapterList &chapters,
                               const std::vector<unsigned int> &sampleSizes,
-                              offset_t textDataOffset,
+                              TagLib::offset_t textDataOffset,
                               unsigned int movieDuration)
   {
     unsigned int count = chapters.size();
@@ -922,8 +922,8 @@ namespace
       if(child->name() != "tref")
         continue;
 
-      const offset_t trefOff = child->offset();
-      const offset_t trefLen = child->length();
+      const TagLib::offset_t trefOff = child->offset();
+      const TagLib::offset_t trefLen = child->length();
 
       file->removeBlock(trefOff, trefLen);
 
@@ -942,13 +942,13 @@ namespace
   }
 
   //! Finds the top-level mdat atom that covers the given file offset.
-  const MP4::Atom *findMdatContaining(const MP4::Atoms *atoms, offset_t fileOffset)
+  const MP4::Atom *findMdatContaining(const MP4::Atoms *atoms, TagLib::offset_t fileOffset)
   {
     for(const auto *atom : atoms->atoms()) {
       if(atom->name() != "mdat")
         continue;
-      const offset_t dataStart = atom->offset() + 8;
-      const offset_t end = atom->offset() + atom->length();
+      const TagLib::offset_t dataStart = atom->offset() + 8;
+      const TagLib::offset_t end = atom->offset() + atom->length();
       if(fileOffset >= dataStart && fileOffset < end)
         return atom;
     }
@@ -959,10 +959,10 @@ namespace
   //! Used to detect mdats that are shared with other tracks (audio data + chapter
   //! text co-located in a single mdat) so we never delete live track data.
   bool mdatIsUsedByAnyTrack(TagLib::File *file, const MP4::Atoms *atoms,
-                            offset_t mdatStart, offset_t mdatSize)
+                            TagLib::offset_t mdatStart, TagLib::offset_t mdatSize)
   {
-    const offset_t dataStart = mdatStart + 8;
-    const offset_t dataEnd = mdatStart + mdatSize;
+    const TagLib::offset_t dataStart = mdatStart + 8;
+    const TagLib::offset_t dataEnd = mdatStart + mdatSize;
 
     const MP4::Atom *moov = atoms->find("moov");
     if(!moov)
@@ -977,7 +977,7 @@ namespace
       unsigned int pos = 4;
       const unsigned int maxPos = data.size() - 4;
       while(count-- && pos <= maxPos) {
-        const auto o = static_cast<offset_t>(data.toUInt(pos));
+        const auto o = static_cast<TagLib::offset_t>(data.toUInt(pos));
         if(o >= dataStart && o < dataEnd)
           return true;
         pos += 4;
@@ -993,7 +993,7 @@ namespace
       unsigned int pos = 4;
       const unsigned int maxPos = data.size() - 8;
       while(count-- && pos <= maxPos) {
-        const offset_t o = data.toLongLong(pos);
+        const TagLib::offset_t o = data.toLongLong(pos);
         if(o >= dataStart && o < dataEnd)
           return true;
         pos += 8;
@@ -1018,13 +1018,13 @@ namespace
                              const MP4::Atom *audioTrak)
   {
     // Identify the chapter text mdat BEFORE removal (while stco is still valid).
-    offset_t chapterMdatOffset = -1;
-    offset_t chapterMdatSize = 0;
+    TagLib::offset_t chapterMdatOffset = -1;
+    TagLib::offset_t chapterMdatSize = 0;
     {
       const std::vector<unsigned int> stco = readStco(file, chapterTrak);
       if(!stco.empty()) {
         if(const MP4::Atom *mdat = findMdatContaining(atoms,
-                                                     static_cast<offset_t>(stco[0]))) {
+                                                     static_cast<TagLib::offset_t>(stco[0]))) {
           chapterMdatOffset = mdat->offset();
           chapterMdatSize = mdat->length();
         }
@@ -1032,8 +1032,8 @@ namespace
     }
 
     // Capture tref/chapter trak locations for mdat offset fix-up below.
-    offset_t trefOff = -1;
-    offset_t trefLen = 0;
+    TagLib::offset_t trefOff = -1;
+    TagLib::offset_t trefLen = 0;
     for(const auto &child : audioTrak->children()) {
       if(child->name() == "tref") {
         trefOff = child->offset();
@@ -1043,8 +1043,8 @@ namespace
     }
 
     // Remove chapter trak FIRST (higher offset in file).
-    const offset_t chapterOff = chapterTrak->offset();
-    const offset_t chapterLen = chapterTrak->length();
+    const TagLib::offset_t chapterOff = chapterTrak->offset();
+    const TagLib::offset_t chapterLen = chapterTrak->length();
 
     // Remove from in-memory tree so updateChunkOffsets skips its stco.
     moov->removeChild(chapterTrak);
@@ -1065,7 +1065,7 @@ namespace
 
     // Shift the original mdat offset by however much of the removed bytes
     // preceded it in the file.
-    offset_t adjustedOffset = chapterMdatOffset;
+    TagLib::offset_t adjustedOffset = chapterMdatOffset;
     if(chapterMdatOffset > chapterOff)
       adjustedOffset -= chapterLen;
     if(trefOff >= 0 && chapterMdatOffset > trefOff)
@@ -1081,7 +1081,7 @@ namespace
     const ByteVector header = file->readBlock(8);
     if(header.size() != 8 || header.mid(4, 4) != "mdat")
       return;
-    if(static_cast<offset_t>(header.toUInt()) != chapterMdatSize)
+    if(static_cast<TagLib::offset_t>(header.toUInt()) != chapterMdatSize)
       return;
 
     file->removeBlock(adjustedOffset, chapterMdatSize);
@@ -1232,9 +1232,9 @@ bool MP4::QtChapterList::write(TagLib::F
   const ByteVector trakMeasure = buildChapterTrak(
     chapterTrackId, timescale, durationMs, workingChapters, sampleSizes, 0,
     movieInfo.duration);
-  const auto totalInsert = static_cast<offset_t>(trefAtom.size() + trakMeasure.size());
+  const auto totalInsert = static_cast<TagLib::offset_t>(trefAtom.size() + trakMeasure.size());
   // Text samples go inside an mdat atom at EOF.  stco offsets point past the 8-byte mdat header.
-  const offset_t textDataOffset = file->length() + totalInsert + 8;
+  const TagLib::offset_t textDataOffset = file->length() + totalInsert + 8;
 
   // Build final trak with correct stco offsets pointing to where text data will land.
   const ByteVector trakAtom = buildChapterTrak(
@@ -1247,7 +1247,7 @@ bool MP4::QtChapterList::write(TagLib::F
 
   // Insert at the end of the audio trak boundary.
   // tref is logically inside audio trak; chapter trak is logically after it.
-  const offset_t insertOffset = audio.trak->offset() + audio.trak->length();
+  const TagLib::offset_t insertOffset = audio.trak->offset() + audio.trak->length();
 
   file->insert(combinedPayload, insertOffset, 0);
 
