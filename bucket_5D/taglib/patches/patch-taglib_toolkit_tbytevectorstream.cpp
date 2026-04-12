--- taglib/toolkit/tbytevectorstream.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/toolkit/tbytevectorstream.cpp
@@ -138,12 +138,12 @@ void ByteVectorStream::clear()
 {
 }
 
-offset_t ByteVectorStream::tell() const
+TagLib::offset_t ByteVectorStream::tell() const
 {
   return d->position;
 }
 
-offset_t ByteVectorStream::length()
+TagLib::offset_t ByteVectorStream::length()
 {
   return d->data.size();
 }
