--- ev.c.orig	2018-12-21 06:59:16 UTC
+++ ev.c
@@ -2760,7 +2760,7 @@ ev_recommended_backends (void) EV_NOEXCE
 {
   unsigned int flags = ev_supported_backends ();
 
-#ifndef __NetBSD__
+#if ! (defined __NetBSD__ || defined __FreeBSD__ || defined __DragonFly__)
   /* kqueue is borked on everything but netbsd apparently */
   /* it usually doesn't work correctly on anything but sockets and pipes */
   flags &= ~EVBACKEND_KQUEUE;
