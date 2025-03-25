--- Source/WTF/wtf/FileSystem.cpp.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/FileSystem.cpp
@@ -47,6 +47,10 @@
 #include <wtf/StdFilesystem.h>
 #endif
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
+
 namespace WTF::FileSystemImpl {
 
 #if HAVE(STD_FILESYSTEM) || HAVE(STD_EXPERIMENTAL_FILESYSTEM)
