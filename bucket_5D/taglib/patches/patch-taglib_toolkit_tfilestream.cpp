--- taglib/toolkit/tfilestream.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/toolkit/tfilestream.cpp
@@ -431,7 +431,7 @@ void FileStream::clear()
 #endif
 }
 
-offset_t FileStream::tell() const
+TagLib::offset_t FileStream::tell() const
 {
 #ifdef _WIN32
 
@@ -452,7 +452,7 @@ offset_t FileStream::tell() const
 #endif
 }
 
-offset_t FileStream::length()
+TagLib::offset_t FileStream::length()
 {
   if(!isOpen()) {
     debug("FileStream::length() -- invalid file.");
