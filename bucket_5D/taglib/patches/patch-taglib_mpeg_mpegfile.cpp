--- taglib/mpeg/mpegfile.cpp.orig	2026-05-17 12:40:31 UTC
+++ taglib/mpeg/mpegfile.cpp
@@ -383,7 +383,7 @@ bool MPEG::File::strip(int tags, bool fr
   return true;
 }
 
-offset_t MPEG::File::nextFrameOffset(offset_t position)
+TagLib::offset_t MPEG::File::nextFrameOffset(TagLib::offset_t position)
 {
   ByteVector frameSyncBytes(2, '\0');
 
@@ -406,7 +406,7 @@ offset_t MPEG::File::nextFrameOffset(off
   }
 }
 
-offset_t MPEG::File::previousFrameOffset(offset_t position)
+TagLib::offset_t MPEG::File::previousFrameOffset(TagLib::offset_t position)
 {
   ByteVector frameSyncBytes(2, '\0');
 
@@ -430,7 +430,7 @@ offset_t MPEG::File::previousFrameOffset
   return -1;
 }
 
-offset_t MPEG::File::firstFrameOffset()
+TagLib::offset_t MPEG::File::firstFrameOffset()
 {
   offset_t position = 0;
 
@@ -440,7 +440,7 @@ offset_t MPEG::File::firstFrameOffset()
   return nextFrameOffset(position);
 }
 
-offset_t MPEG::File::lastFrameOffset()
+TagLib::offset_t MPEG::File::lastFrameOffset()
 {
   offset_t position;
 
@@ -512,7 +512,7 @@ void MPEG::File::read(bool readPropertie
   ID3v1Tag(true);
 }
 
-offset_t MPEG::File::findID3v2(Properties::ReadStyle readStyle)
+TagLib::offset_t MPEG::File::findID3v2(Properties::ReadStyle readStyle)
 {
   if(!isValid())
     return -1;
