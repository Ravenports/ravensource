--- tinyxml2.cpp.orig	2021-05-28 20:31:43 UTC
+++ tinyxml2.cpp
@@ -103,7 +103,7 @@ distribution.
 #if defined(_WIN64)
 	#define TIXML_FSEEK _fseeki64
 	#define TIXML_FTELL _ftelli64
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	#define TIXML_FSEEK fseeko
 	#define TIXML_FTELL ftello
 #elif defined(__unix__) && defined(__x86_64__)
