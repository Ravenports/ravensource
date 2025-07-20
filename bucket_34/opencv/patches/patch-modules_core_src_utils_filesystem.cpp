--- modules/core/src/utils/filesystem.cpp.orig	2025-07-02 07:54:13 UTC
+++ modules/core/src/utils/filesystem.cpp
@@ -34,7 +34,7 @@
 #include <errno.h>
 #include <io.h>
 #include <stdio.h>
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__ || defined __sun__ || defined __DragonFly__ || defined __NetBSD__
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -194,7 +194,7 @@ cv::String getcwd()
     sz = GetCurrentDirectoryA((DWORD)buf.size(), buf.data());
     return cv::String(buf.data(), (size_t)sz);
 #endif
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__ || defined __sun__ || defined __DragonFly__ || defined __NetBSD__
     for(;;)
     {
         char* p = ::getcwd(buf.data(), buf.size());
@@ -228,7 +228,7 @@ bool createDirectory(const cv::String& p
 #else
     int result = _mkdir(path.c_str());
 #endif
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__ || defined __sun__ || defined __DragonFly__ || defined __NetBSD__
     int result = mkdir(path.c_str(), 0777);
 #else
     int result = -1;
@@ -343,7 +343,7 @@ private:
     Impl& operator=(const Impl&); // disabled
 };
 
-#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__
+#elif defined __linux__ || defined __APPLE__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __CYGWIN__ || defined __sun__ || defined __DragonFly__ || defined __NetBSD__
 
 struct FileLock::Impl
 {
@@ -457,7 +457,7 @@ cv::String getCacheDirectory(const char*
             default_cache_path = "/tmp/";
             CV_LOG_WARNING(NULL, "Using world accessible cache directory. This may be not secure: " << default_cache_path);
         }
-#elif defined __linux__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__
+#elif defined __linux__ || defined __HAIKU__ || defined __FreeBSD__ || defined __GNU__ || defined __DragonFly__ || defined __sun__ || defined __NetBSD__
         // https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html
         if (default_cache_path.empty())
         {
