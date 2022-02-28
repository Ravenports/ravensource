--- src/third_party/httplib.cpp.orig	2022-02-27 20:03:02 UTC
+++ src/third_party/httplib.cpp
@@ -800,7 +800,7 @@ bool bind_ip_address(socket_t sock, cons
   return ret;
 }
 
-#if !defined _WIN32 && !defined ANDROID
+#if !defined _WIN32 && !defined ANDROID && !defined __sun
 #define USE_IF2IP
 #endif
 
