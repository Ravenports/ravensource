--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -80,7 +80,7 @@ CString currentExecutablePath()
     ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
     if (result == -1)
         return { };
-    return CString(readLinkBuffer, result);
+    return CString({ readLinkBuffer, static_cast<size_t>(result) });
 }
 #elif OS(WINDOWS)
 CString currentExecutablePath()
