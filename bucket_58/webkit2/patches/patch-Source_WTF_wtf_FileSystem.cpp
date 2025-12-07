--- Source/WTF/wtf/FileSystem.cpp.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/FileSystem.cpp
@@ -49,6 +49,10 @@
 #include <wtf/StdFilesystem.h>
 #endif
 
+#ifndef MAP_FILE
+#define MAP_FILE	0
+#endif
+
 namespace WTF::FileSystemImpl {
 
 #if HAVE(STD_FILESYSTEM) || HAVE(STD_EXPERIMENTAL_FILESYSTEM)
