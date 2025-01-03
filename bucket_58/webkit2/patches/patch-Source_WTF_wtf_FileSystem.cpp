$NetBSD: patch-Source_WTF_wtf_FileSystem.cpp,v 1.3 2020/09/11 14:47:35 leot Exp $

Support MAP_FILE if unavailable.

--- Source/WTF/wtf/FileSystem.cpp.orig	2024-12-18 08:50:45 UTC
+++ Source/WTF/wtf/FileSystem.cpp
@@ -361,6 +361,9 @@ bool MappedFileData::mapFileHandle(Platf
 #endif
     }
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
     void* data = mmap(0, size, pageProtection, MAP_FILE | (mapMode == MappedFileMode::Shared ? MAP_SHARED : MAP_PRIVATE), fd, 0);
 
     if (data == MAP_FAILED) {
