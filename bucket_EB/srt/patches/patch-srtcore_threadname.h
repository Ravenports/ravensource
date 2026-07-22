--- srtcore/threadname.h.orig	2026-04-17 06:56:57 UTC
+++ srtcore/threadname.h
@@ -104,7 +104,7 @@ class ThreadName
     #if defined(__APPLE__)
             return pthread_setname_np(name) == 0;
     #elif defined(__NetBSD__)
-            return pthread_setname_np(pthread_self(), "%s", name) == 0;
+            return pthread_setname_np(pthread_self(), "%s", (void *)name) == 0;
     #else
             return pthread_setname_np(pthread_self(), name) == 0;
     #endif
