--- lib/signal.in.h.orig	2023-01-18 17:15:51 UTC
+++ lib/signal.in.h
@@ -66,6 +66,7 @@
    But avoid namespace pollution on glibc systems.*/
 #if (@GNULIB_PTHREAD_SIGMASK@ || defined GNULIB_POSIXCHECK) \
     && ((defined __APPLE__ && defined __MACH__) \
+        || defined __DragonFly__ \
         || (defined __FreeBSD__ && __FreeBSD__ < 8) \
         || (defined __OpenBSD__ && OpenBSD < 201205) \
         || defined __osf__ || defined __sun || defined __ANDROID__ \
