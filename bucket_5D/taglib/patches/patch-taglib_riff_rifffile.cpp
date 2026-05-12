--- taglib/riff/rifffile.cpp.orig	2026-05-04 14:43:04 UTC
+++ taglib/riff/rifffile.cpp
@@ -36,7 +36,7 @@ using namespace TagLib;
 struct Chunk
 {
   ByteVector   name;
-  offset_t offset;
+  TagLib::offset_t offset;
   unsigned int size;
   unsigned int padding;
 };
@@ -103,7 +103,7 @@ unsigned int RIFF::File::chunkDataSize(u
   return d->chunks[i].size;
 }
 
-offset_t RIFF::File::chunkOffset(unsigned int i) const
+TagLib::offset_t RIFF::File::chunkOffset(unsigned int i) const
 {
   if(i >= d->chunks.size()) {
     debug("RIFF::File::chunkOffset() - Index out of range. Returning 0.");
