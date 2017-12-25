--- ev.c.orig	2016-12-28 04:23:00 UTC
+++ ev.c
@@ -2753,7 +2753,7 @@ ev_recommended_backends (void) EV_THROW
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if ! (defined __NetBSD__ || defined __FreeBSD__ || defined __DragonFly__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
