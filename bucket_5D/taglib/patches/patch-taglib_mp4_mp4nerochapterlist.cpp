--- taglib/mp4/mp4nerochapterlist.cpp.orig	2026-05-04 14:43:04 UTC
+++ taglib/mp4/mp4nerochapterlist.cpp
@@ -42,7 +42,7 @@ namespace
   // Update parent atom sizes along a path when child size changes by delta.
   // Mirrors MP4::Tag::updateParents().
   void updateParentSizes(TagLib::File *file, const MP4::AtomList &path,
-                         offset_t delta, int ignore = 0)
+                         TagLib::offset_t delta, int ignore = 0)
   {
     if(static_cast<int>(path.size()) <= ignore)
       return;
@@ -70,7 +70,7 @@ namespace
   // Update stco/co64/tfhd chunk offsets when file content shifts.
   // Mirrors MP4::Tag::updateOffsets().
   void updateChunkOffsets(TagLib::File *file, const MP4::Atoms *atoms,
-                          offset_t delta, offset_t offset)
+                          TagLib::offset_t delta, TagLib::offset_t offset)
   {
     if(const MP4::Atom *moov = atoms->find("moov")) {
       const MP4::AtomList stco = moov->findall("stco", true);
@@ -84,7 +84,7 @@ namespace
         unsigned int pos = 4;
         const unsigned int maxPos = data.size() - 4;
         while(count-- && pos <= maxPos) {
-          auto o = static_cast<offset_t>(data.toUInt(pos));
+          auto o = static_cast<TagLib::offset_t>(data.toUInt(pos));
           if(o > offset)
             o += delta;
           file->writeBlock(ByteVector::fromUInt(static_cast<unsigned int>(o)));
@@ -248,9 +248,9 @@ bool MP4::NeroChapterList::write(TagLib:
 
   if(const Atom *existingChpl = atoms.find("moov", "udta", "chpl")) {
     // Replace existing chpl atom
-    const offset_t offset = existingChpl->offset();
-    const offset_t oldLength = existingChpl->length();
-    const offset_t delta = static_cast<offset_t>(chplAtom.size()) - oldLength;
+    const TagLib::offset_t offset = existingChpl->offset();
+    const TagLib::offset_t oldLength = existingChpl->length();
+    const TagLib::offset_t delta = static_cast<TagLib::offset_t>(chplAtom.size()) - oldLength;
 
     file->insert(chplAtom, offset, oldLength);
 
@@ -266,7 +266,7 @@ bool MP4::NeroChapterList::write(TagLib:
 
     if(AtomList udtaPath = atoms.path("moov", "udta"); udtaPath.size() == 2) {
       // udta exists -- insert chpl at the beginning of udta's content
-      const offset_t insertOffset = udtaPath.back()->offset() + 8;
+      const TagLib::offset_t insertOffset = udtaPath.back()->offset() + 8;
       file->insert(chplAtom, insertOffset, 0);
 
       updateParentSizes(file, udtaPath, chplAtom.size());
@@ -282,7 +282,7 @@ bool MP4::NeroChapterList::write(TagLib:
         return false;
       }
 
-      const offset_t insertOffset = moovPath.back()->offset() + 8;
+      const TagLib::offset_t insertOffset = moovPath.back()->offset() + 8;
       file->insert(udtaAtom, insertOffset, 0);
 
       updateParentSizes(file, moovPath, udtaAtom.size());
@@ -306,8 +306,8 @@ bool MP4::NeroChapterList::remove(TagLib
     return true;
   }
 
-  const offset_t offset = chpl->offset();
-  const offset_t length = chpl->length();
+  const TagLib::offset_t offset = chpl->offset();
+  const TagLib::offset_t length = chpl->length();
 
   file->removeBlock(offset, length);
 
