--- src/third_party/httplib.cpp.orig	2021-09-28 19:39:22 UTC
+++ src/third_party/httplib.cpp
@@ -730,7 +730,7 @@ bool bind_ip_address(socket_t sock, cons
   return ret;
 }
 
-#if !defined _WIN32 && !defined ANDROID
+#if !defined _WIN32 && !defined ANDROID && !defined __sun
 #define USE_IF2IP
 #endif
 
