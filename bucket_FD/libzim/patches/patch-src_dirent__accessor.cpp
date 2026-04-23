--- src/dirent_accessor.cpp.orig	2026-04-06 11:14:19 UTC
+++ src/dirent_accessor.cpp
@@ -57,16 +57,16 @@ std::shared_ptr<const Dirent> DirectDire
   return dirent;
 }
 
-offset_t DirectDirentAccessor::getOffset(entry_index_t idx) const
+zim::offset_t DirectDirentAccessor::getOffset(entry_index_t idx) const
 {
   if (idx >= m_direntCount) {
     throw std::out_of_range("entry index out of range");
   }
-  offset_t offset(mp_pathPtrReader->read_uint<offset_type>(offset_t(sizeof(offset_type)*idx.v)));
+  zim::offset_t offset(mp_pathPtrReader->read_uint<zim::offset_type>(zim::offset_t(sizeof(zim::offset_type)*idx.v)));
   return offset;
 }
 
-std::shared_ptr<const Dirent> DirectDirentAccessor::readDirent(offset_t offset) const
+std::shared_ptr<const Dirent> DirectDirentAccessor::readDirent(zim::offset_t offset) const
 {
   return mp_direntReader->readDirent(offset);
 }
@@ -83,7 +83,7 @@ entry_index_t IndirectDirentAccessor::ge
   if (idx >= m_direntCount) {
     throw std::out_of_range("entry index out of range");
   }
-  entry_index_t index(mp_indexReader->read_uint<entry_index_type>(offset_t(sizeof(entry_index_t)*idx.v)));
+  entry_index_t index(mp_indexReader->read_uint<entry_index_type>(zim::offset_t(sizeof(entry_index_t)*idx.v)));
   return index;
 }
 
