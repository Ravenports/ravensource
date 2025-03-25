$NetBSD: patch-libxfsm_xfsm-shutdown-common.h,v 1.1 2019/05/23 02:56:07 gutteridge Exp $

Add NetBSD commands.

--- libxfsm/xfsm-shutdown-common.h.orig	2024-09-15 22:04:31 UTC
+++ libxfsm/xfsm-shutdown-common.h
@@ -70,6 +70,11 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
 
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND      "/sbin/sysctl -w hw.acpi.sleep.state=1"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/sbin/sysctl -w hw.acpi.sleep.state=4"
+#endif
+
 #ifdef BACKEND_TYPE_SOLARIS
 #define UP_BACKEND_SUSPEND_COMMAND "/usr/bin/sys-suspend"
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/bin/false"
