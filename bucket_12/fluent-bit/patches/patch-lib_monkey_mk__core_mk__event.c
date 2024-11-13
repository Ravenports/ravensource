--- lib/monkey/mk_core/mk_event.c.orig	2024-11-04 22:36:47 UTC
+++ lib/monkey/mk_core/mk_event.c
@@ -42,7 +42,7 @@
     /* do our best based on the operating system */
     #if defined(__linux__)
         #include "mk_event_epoll.c"
-    #elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__OpenBSD__)
+    #elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
         #include "mk_event_kqueue.c"
     #elif defined(_WIN32)
         #include "mk_event_libevent.c"