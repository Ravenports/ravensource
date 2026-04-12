--- taglib/mp4/mp4atom.cpp.orig	2026-01-31 07:25:47 UTC
+++ taglib/mp4/mp4atom.cpp
@@ -44,9 +44,9 @@ namespace {
 class MP4::Atom::AtomPrivate
 {
 public:
-  explicit AtomPrivate(offset_t ofs) : offset(ofs) {}
-  offset_t offset;
-  offset_t length { 0 };
+  explicit AtomPrivate(TagLib::offset_t ofs) : offset(ofs) {}
+  TagLib::offset_t offset;
+  TagLib::offset_t length { 0 };
   TagLib::ByteVector name;
   AtomList children;
 };
@@ -94,7 +94,7 @@ MP4::Atom::Atom(File *file)
   for(auto c : containers) {
     if(d->name == c) {
       if(d->name == "meta") {
-        offset_t posAfterMeta = file->tell();
+        TagLib::offset_t posAfterMeta = file->tell();
         static constexpr std::array metaChildrenNames {
           "hdlr", "ilst", "mhdr", "ctry", "lang"
         };
@@ -162,7 +162,7 @@ MP4::Atom::path(MP4::AtomList &path, con
   return it != d->children.cend() ? (*it)->path(path, name2, name3) : false;
 }
 
-void MP4::Atom::addToOffset(offset_t delta)
+void MP4::Atom::addToOffset(TagLib::offset_t delta)
 {
   d->offset += delta;
 }
@@ -182,12 +182,12 @@ bool MP4::Atom::removeChild(Atom *meta)
   return false;
 }
 
-offset_t MP4::Atom::offset() const
+TagLib::offset_t MP4::Atom::offset() const
 {
   return d->offset;
 }
 
-offset_t MP4::Atom::length() const
+TagLib::offset_t MP4::Atom::length() const
 {
   return d->length;
 }
@@ -215,7 +215,7 @@ MP4::Atoms::Atoms(File *file) :
   d->atoms.setAutoDelete(true);
 
   file->seek(0, File::End);
-  offset_t end = file->tell();
+  TagLib::offset_t end = file->tell();
   file->seek(0);
   while(file->tell() + 8 <= end) {
     auto atom = new MP4::Atom(file);
