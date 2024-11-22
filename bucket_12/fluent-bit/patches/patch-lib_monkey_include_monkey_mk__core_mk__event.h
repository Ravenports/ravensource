--- lib/monkey/include/monkey/mk_core/mk_event.h.orig	2024-11-17 03:19:24 UTC
+++ lib/monkey/include/monkey/mk_core/mk_event.h
@@ -84,7 +84,7 @@
     /* do our best based on the operating system */
     #if defined(__linux__)
         #include "mk_event_epoll.h"
-    #elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__OpenBSD__)
+    #elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
         #include "mk_event_kqueue.h"
     #elif defined(_WIN32)
         #include "mk_event_libevent.h"
