--- taglib/ogg/oggpage.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/ogg/oggpage.cpp
@@ -128,7 +128,7 @@ Ogg::Page::Page(Ogg::File *file, offset_
 
 Ogg::Page::~Page() = default;
 
-offset_t Ogg::Page::fileOffset() const
+TagLib::offset_t Ogg::Page::fileOffset() const
 {
   return d->fileOffset;
 }
