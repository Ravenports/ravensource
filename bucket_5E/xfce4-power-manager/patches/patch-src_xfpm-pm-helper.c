--- src/xfpm-pm-helper.c.orig	2024-06-09 15:35:09 UTC
+++ src/xfpm-pm-helper.c
@@ -77,6 +77,11 @@
 #define UP_BACKEND_SUSPEND_COMMAND  "/usr/sbin/zzz"
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
+#ifdef __NetBSD__
+#define UP_BACKEND_SUSPEND_COMMAND      "/sbin/sysctl -w hw.acpi.sleep.state=1"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/sbin/sysctl -w hw.acpi.sleep.state=4"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
 
 
 static gboolean
