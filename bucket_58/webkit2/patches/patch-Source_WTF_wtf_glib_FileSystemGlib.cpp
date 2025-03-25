--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -82,7 +82,7 @@ CString currentExecutablePath()
     ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
     if (result == -1)
         return { };
-    return CString(readLinkBuffer, result);
+    return CString({ readLinkBuffer, static_cast<size_t>(result) });
 }
 #elif OS(WINDOWS)
 CString currentExecutablePath()
