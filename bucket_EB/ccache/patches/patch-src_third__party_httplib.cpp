--- src/third_party/httplib.cpp.orig	2022-11-21 18:53:32 UTC
+++ src/third_party/httplib.cpp
@@ -821,7 +821,7 @@ bool bind_ip_address(socket_t sock, cons
   return ret;
 }
 
-#if !defined _WIN32 && !defined ANDROID
+#if !defined _WIN32 && !defined ANDROID && !defined __sun
 #define USE_IF2IP
 #endif
 
