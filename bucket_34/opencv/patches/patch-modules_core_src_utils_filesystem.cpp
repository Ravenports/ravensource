--- modules/core/src/utils/filesystem.cpp.orig	2018-12-21 14:31:20 UTC
+++ modules/core/src/utils/filesystem.cpp
@@ -34,7 +34,7 @@
 #include <errno.h>
 #include <io.h>
 #include <stdio.h>
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __DragonFly__ || defined __sun__
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -178,7 +178,7 @@ cv::String getcwd()
     sz = GetCurrentDirectoryA((DWORD)buf.size(), buf.data());
     return cv::String(buf.data(), (size_t)sz);
 #endif
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __DragonFly__ || defined __sun__
     for(;;)
     {
         char* p = ::getcwd(buf.data(), buf.size());
@@ -212,7 +212,7 @@ bool createDirectory(const cv::String& p
 #else
     int result = _mkdir(path.c_str());
 #endif
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __DragonFly__ || defined __sun__
     int result = mkdir(path.c_str(), 0777);
 #else
     int result = -1;
@@ -327,7 +327,7 @@ private:
     Impl& operator=(const Impl&); // disabled
 };
 
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __DragonFly__ || defined __sun__
 
 struct FileLock::Impl
 {
