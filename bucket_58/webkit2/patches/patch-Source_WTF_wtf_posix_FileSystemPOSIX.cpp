--- Source/WTF/wtf/posix/FileSystemPOSIX.cpp.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/posix/FileSystemPOSIX.cpp
@@ -110,6 +110,9 @@ std::optional<WallTime> fileCreationTime
         return std::nullopt;
 
     return WallTime::fromRawSeconds(fileInfo.stx_btime.tv_sec);
+#elif defined __DragonFly__
+    /* st_birthtime is not in the stat structure on DragonFly */
+    return std::nullopt;
 #elif OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
     struct stat fileInfo;
 
