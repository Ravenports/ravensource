--- taglib/mpeg/mpegfile.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/mpeg/mpegfile.cpp
@@ -381,7 +381,7 @@ bool MPEG::File::strip(int tags, bool fr
   return true;
 }
 
-offset_t MPEG::File::nextFrameOffset(offset_t position)
+TagLib::offset_t MPEG::File::nextFrameOffset(TagLib::offset_t position)
 {
   ByteVector frameSyncBytes(2, '\0');
 
@@ -404,7 +404,7 @@ offset_t MPEG::File::nextFrameOffset(off
   }
 }
 
-offset_t MPEG::File::previousFrameOffset(offset_t position)
+TagLib::offset_t MPEG::File::previousFrameOffset(TagLib::offset_t position)
 {
   ByteVector frameSyncBytes(2, '\0');
 
@@ -428,7 +428,7 @@ offset_t MPEG::File::previousFrameOffset
   return -1;
 }
 
-offset_t MPEG::File::firstFrameOffset()
+TagLib::offset_t MPEG::File::firstFrameOffset()
 {
   offset_t position = 0;
 
@@ -438,7 +438,7 @@ offset_t MPEG::File::firstFrameOffset()
   return nextFrameOffset(position);
 }
 
-offset_t MPEG::File::lastFrameOffset()
+TagLib::offset_t MPEG::File::lastFrameOffset()
 {
   offset_t position;
 
@@ -510,7 +510,7 @@ void MPEG::File::read(bool readPropertie
   ID3v1Tag(true);
 }
 
-offset_t MPEG::File::findID3v2(Properties::ReadStyle readStyle)
+TagLib::offset_t MPEG::File::findID3v2(Properties::ReadStyle readStyle)
 {
   if(!isValid())
     return -1;
