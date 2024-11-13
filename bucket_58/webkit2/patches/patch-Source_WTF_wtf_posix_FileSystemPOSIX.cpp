--- Source/WTF/wtf/posix/FileSystemPOSIX.cpp.orig	2024-10-21 09:00:02 UTC
+++ Source/WTF/wtf/posix/FileSystemPOSIX.cpp
@@ -195,6 +195,9 @@ std::optional<WallTime> fileCreationTime
         return std::nullopt;
 
     return WallTime::fromRawSeconds(fileInfo.stx_btime.tv_sec);
+#elif defined __DragonFly__
+    /* st_birthtime is not in the stat structure on DragonFly */
+    return std::nullopt;
 #elif OS(DARWIN) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
     struct stat fileInfo;
 
