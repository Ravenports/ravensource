--- src/third_party/httplib.cpp.orig	2021-11-17 19:31:58 UTC
+++ src/third_party/httplib.cpp
@@ -764,7 +764,7 @@ bool bind_ip_address(socket_t sock, cons
   return ret;
 }
 
-#if !defined _WIN32 && !defined ANDROID
+#if !defined _WIN32 && !defined ANDROID && !defined __sun
 #define USE_IF2IP
 #endif
 
