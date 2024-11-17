--- xfce4-session/xfsm-shutdown-fallback.c.orig	2024-06-09 15:28:49 UTC
+++ xfce4-session/xfsm-shutdown-fallback.c
@@ -72,10 +72,8 @@
 
 #if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define __BACKEND_TYPE_BSD__ 1
-#ifdef HAVE_SYS_SYSCTL_H
 #include <sys/sysctl.h>
 #endif
-#endif
 
 #define POLKIT_AUTH_SHUTDOWN_XFSM     "org.xfce.session.xfsm-shutdown-helper"
 #define POLKIT_AUTH_RESTART_XFSM      "org.xfce.session.xfsm-shutdown-helper"
