--- taglib/tagutils.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/tagutils.cpp
@@ -36,7 +36,7 @@
 
 using namespace TagLib;
 
-offset_t Utils::findID3v1(File *file)
+TagLib::offset_t Utils::findID3v1(File *file)
 {
   if(!file->isValid())
     return -1;
@@ -45,7 +45,7 @@ offset_t Utils::findID3v1(File *file)
 
   if (file->length() >= 131) {
     file->seek(-131, File::End);
-    const offset_t p = file->tell() + 3;
+    const TagLib::offset_t p = file->tell() + 3;
 
     if(const TagLib::ByteVector data = file->readBlock(8);
        data.containsAt(ID3v1::Tag::fileIdentifier(), 3) &&
@@ -58,7 +58,7 @@ offset_t Utils::findID3v1(File *file)
       return p;
   } else {
     file->seek(-128, File::End);
-    const offset_t p = file->tell();
+    const TagLib::offset_t p = file->tell();
 
     if(file->readBlock(3) == ID3v1::Tag::fileIdentifier())
       return p;
@@ -67,7 +67,7 @@ offset_t Utils::findID3v1(File *file)
   return -1;
 }
 
-offset_t Utils::findID3v2(File *file)
+TagLib::offset_t Utils::findID3v2(File *file)
 {
   if(!file->isValid())
     return -1;
@@ -80,7 +80,7 @@ offset_t Utils::findID3v2(File *file)
   return -1;
 }
 
-offset_t Utils::findAPE(File *file, offset_t id3v1Location)
+TagLib::offset_t Utils::findAPE(File *file, TagLib::offset_t id3v1Location)
 {
   if(!file->isValid())
     return -1;
@@ -90,7 +90,7 @@ offset_t Utils::findAPE(File *file, offs
   else
     file->seek(-32, File::End);
 
-  const offset_t p = file->tell();
+  const TagLib::offset_t p = file->tell();
 
   if(file->readBlock(8) ==
 #ifdef TAGLIB_WITH_APE
@@ -105,13 +105,13 @@ offset_t Utils::findAPE(File *file, offs
 }
 
 ByteVector TagLib::Utils::readHeader(IOStream *stream, unsigned int length,
-                                     bool skipID3v2, offset_t *headerOffset)
+                                     bool skipID3v2, TagLib::offset_t *headerOffset)
 {
   if(!stream || !stream->isOpen())
     return ByteVector();
 
-  const offset_t originalPosition = stream->tell();
-  offset_t bufferOffset = 0;
+  const TagLib::offset_t originalPosition = stream->tell();
+  TagLib::offset_t bufferOffset = 0;
 
   if(skipID3v2) {
     stream->seek(0);
