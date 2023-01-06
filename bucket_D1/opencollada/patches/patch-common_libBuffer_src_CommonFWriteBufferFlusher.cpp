--- common/libBuffer/src/CommonFWriteBufferFlusher.cpp.orig	2018-01-13 00:23:52 UTC
+++ common/libBuffer/src/CommonFWriteBufferFlusher.cpp
@@ -90,7 +90,7 @@ namespace Common
 		FilePosType currentPos = ftello64(mStream);
 #elif defined( _WIN32)
 		FilePosType currentPos = _ftelli64(mStream);
-#elif defined (__APPLE__) || defined(__FreeBSD__)
+#elif defined (__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 		FilePosType currentPos = ftello(mStream);
 #else
 		FilePosType currentPos = ftello64(mStream);
@@ -115,7 +115,7 @@ namespace Common
   			return (fseeko64(mStream,0,SEEK_END) == 0);
 #elif defined( _WIN32)
 			return (_fseeki64(mStream, 0, SEEK_END) == 0);
-#elif defined (__APPLE__) || defined(__FreeBSD__)
+#elif defined (__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 			return (fseeko(mStream, 0, SEEK_END) == 0);
 #else
 			return (fseeko64(mStream, 0, SEEK_END) == 0);
@@ -135,7 +135,7 @@ namespace Common
   				bool success = (fseeko64(mStream,pos,SEEK_SET) == 0);
 #elif defined( _WIN32)
 				bool success = (_fseeki64(mStream, pos, SEEK_SET) == 0);
-#elif defined (__APPLE__) || defined(__FreeBSD__)
+#elif defined (__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 				bool success = (fseeko(mStream, pos, SEEK_SET) == 0);
 #else
 				bool success = (fseeko64(mStream, pos, SEEK_SET) == 0);
