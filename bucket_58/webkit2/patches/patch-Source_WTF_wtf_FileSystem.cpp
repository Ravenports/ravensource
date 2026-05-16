--- Source/WTF/wtf/FileSystem.cpp.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/FileSystem.cpp
@@ -50,6 +50,10 @@
 #include <wtf/StdFilesystem.h>
 #endif
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
+
 namespace WTF::FileSystemImpl {
 
 #if HAVE(STD_FILESYSTEM) || HAVE(STD_EXPERIMENTAL_FILESYSTEM)
