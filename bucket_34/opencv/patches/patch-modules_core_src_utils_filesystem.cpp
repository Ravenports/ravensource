--- modules/core/src/utils/filesystem.cpp.orig	2017-12-22 19:46:21 UTC
+++ modules/core/src/utils/filesystem.cpp
@@ -33,7 +33,7 @@
 #include <errno.h>
 #include <io.h>
 #include <stdio.h>
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined __FreeBSD__ || defined __DragonFly__
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -156,7 +156,7 @@ cv::String getcwd()
     sz = GetCurrentDirectoryA((DWORD)buf.size(), (char*)buf);
     return cv::String((char*)buf, (size_t)sz);
 #endif
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined __FreeBSD__ || defined __DragonFly__
     for(;;)
     {
         char* p = ::getcwd((char*)buf, buf.size());
@@ -190,7 +190,7 @@ bool createDirectory(const cv::String& p
 #else
     int result = _mkdir(path.c_str());
 #endif
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined __FreeBSD__ || defined __DragonFly__
     int result = mkdir(path.c_str(), 0777);
 #else
     int result = -1;
@@ -305,7 +305,7 @@ private:
     Impl& operator=(const Impl&); // disabled
 };
 
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined __FreeBSD__ || defined __DragonFly__
 
 struct FileLock::Impl
 {
