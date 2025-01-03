--- xfce4-session/xfsm-shutdown-fallback.c.orig	2024-11-04 16:33:53 UTC
+++ xfce4-session/xfsm-shutdown-fallback.c
@@ -30,10 +30,8 @@
 
 #if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define __BACKEND_TYPE_BSD__ 1
-#ifdef HAVE_SYS_SYSCTL_H
 #include <sys/sysctl.h>
 #endif
-#endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
