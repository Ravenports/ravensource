--- ev.c.orig	2019-12-21 16:08:22 UTC
+++ ev.c
@@ -3001,7 +3001,7 @@ ev_recommended_backends (void) EV_NOEXCE
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if ! (defined __NetBSD__ || defined __FreeBSD__ || defined __DragonFly__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
