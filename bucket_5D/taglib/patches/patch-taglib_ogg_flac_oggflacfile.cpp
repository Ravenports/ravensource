--- taglib/ogg/flac/oggflacfile.cpp.orig	2026-01-18 19:08:23 UTC
+++ taglib/ogg/flac/oggflacfile.cpp
@@ -206,7 +206,7 @@ ByteVector Ogg::FLAC::File::xiphCommentD
   return d->xiphCommentData;
 }
 
-offset_t Ogg::FLAC::File::streamLength()
+TagLib::offset_t Ogg::FLAC::File::streamLength()
 {
   scan();
   return d->streamLength;
