--- deps/v8/src/d8/d8-posix.cc.orig	2025-11-16 23:17:50 UTC
+++ deps/v8/src/d8/d8-posix.cc
@@ -345,7 +345,7 @@ static Local<Value> GetStdout(Isolate* i
 // See http://code.google.com/p/v8/issues/detail?id=401.
 #if defined(WNOWAIT) && !defined(ANDROID) && !defined(__APPLE__) && \
     !defined(__NetBSD__) && !defined(__Fuchsia__)
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #define HAS_WAITID 1
 #endif
 #endif
