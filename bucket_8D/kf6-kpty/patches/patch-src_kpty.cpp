--- src/kpty.cpp.orig	2024-08-02 11:15:14 UTC
+++ src/kpty.cpp
@@ -73,7 +73,9 @@ public:
     int cmdFd;
 };
 #else
+# if defined __MidnightBSD__ || defined __NetBSD__ || defined __linux__ 
 #include <utmp.h>
+# endif
 #if HAVE_UTMPX
 #include <utmpx.h>
 #endif
