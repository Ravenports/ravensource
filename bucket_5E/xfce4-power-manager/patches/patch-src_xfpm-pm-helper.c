--- src/xfpm-pm-helper.c.orig	2024-11-21 06:26:21 UTC
+++ src/xfpm-pm-helper.c
@@ -82,6 +82,16 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
 #endif
+#ifdef __NetBSD__
+#define UP_BACKEND_SUSPEND_COMMAND      "/sbin/sysctl -w hw.acpi.sleep.state=1"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/sbin/sysctl -w hw.acpi.sleep.state=4"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
+#ifdef __sun
+#define UP_BACKEND_SUSPEND_COMMAND      "/usr/sbin/uadmin 3 20"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/usr/sbin/uadmin 4 0"
+#define UP_BACKEND_HYBRID_SLEEP_COMMAND "/usr/bin/false"
+#endif
 
 
 static gboolean
