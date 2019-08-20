--- src/lib/VSDMetaData.cpp.orig	2017-10-21 14:38:56 UTC
+++ src/lib/VSDMetaData.cpp
@@ -312,7 +312,7 @@ bool libvisio::VSDMetaData::parseTimes(l
   uint32_t firstDirSectorLocation = readU32(input);
 
   // Seek to the Root Directory Entry
-  size_t sectorSize = std::pow(2, sectorShift);
+  size_t sectorSize = 1UL << sectorShift;
   input->seek((firstDirSectorLocation + 1) * sectorSize, librevenge::RVNG_SEEK_SET);
   // DirectoryEntryName: 64 bytes
   // DirectoryEntryNameLength: 2 bytes
