--- taglib/toolkit/tfile.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/toolkit/tfile.cpp
@@ -129,7 +129,7 @@ void File::writeBlock(const ByteVector &
   d->stream->writeBlock(data);
 }
 
-offset_t File::find(const ByteVector &pattern, offset_t fromOffset, const ByteVector &before)
+TagLib::offset_t File::find(const ByteVector &pattern, offset_t fromOffset, const ByteVector &before)
 {
   if(!d->stream || pattern.size() > bufferSize())
       return -1;
@@ -224,7 +224,7 @@ offset_t File::find(const ByteVector &pa
 }
 
 
-offset_t File::rfind(const ByteVector &pattern, offset_t fromOffset, const ByteVector &before)
+TagLib::offset_t File::rfind(const ByteVector &pattern, offset_t fromOffset, const ByteVector &before)
 {
   if(!d->stream || pattern.size() > bufferSize())
       return -1;
@@ -337,12 +337,12 @@ void File::clear()
   d->stream->clear();
 }
 
-offset_t File::tell() const
+TagLib::offset_t File::tell() const
 {
   return d->stream->tell();
 }
 
-offset_t File::length()
+TagLib::offset_t File::length()
 {
   return d->stream->length();
 }
