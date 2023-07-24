--- src/futils.cpp.orig	2023-05-08 16:01:13 UTC
+++ src/futils.cpp
@@ -30,9 +30,11 @@ namespace fs = std::experimental::filesy
 // clang-format on
 #endif
 
+#ifndef __NetBSD__
 #if __has_include(<libproc.h>)
 #include <libproc.h>
 #endif
+#endif
 
 #if __has_include(<unistd.h>)
 #include <unistd.h>  // for stat()
@@ -360,7 +362,7 @@ std::string getProcessPath() {
     TCHAR pathbuf[MAX_PATH];
     GetModuleFileName(nullptr, pathbuf, MAX_PATH);
     auto path = fs::path(pathbuf);
-#elif __has_include(<libproc.h>)
+#elif defined(PROC_PIDPATHINFO_MAXSIZE)
     char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
     proc_pidpath(getpid(), pathbuf, sizeof(pathbuf));
     auto path = fs::path(pathbuf);
