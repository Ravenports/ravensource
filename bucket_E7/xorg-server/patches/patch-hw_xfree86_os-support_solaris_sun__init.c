--- hw/xfree86/os-support/solaris/sun_init.c.orig	2024-12-17 17:51:31 UTC
+++ hw/xfree86/os-support/solaris/sun_init.c
@@ -54,6 +54,22 @@ static int xf86StartVT = -1;
 static int vtEnabled = 0;
 #endif
 
+#ifdef __sun__
+#define VTIOC		('V'<<8)
+#define VT_OPENQRY	(VTIOC|1)
+#define VT_SETMODE	(VTIOC|2)
+#define VT_GETMODE	(VTIOC|3)
+#define VT_ACTIVATE	(VTIOC|5)
+#define VT_WAITACTIVE	(VTIOC|6)
+#define VT_GETSTATE	(VTIOC|100)
+#define VT_ENABLED	(VTIOC|101)
+#define VT_SETDISPINFO	(VTIOC|103)
+#define VT_GET_CONSUSER	(VTIOC|108)
+#define VT_SET_CONSUSER	(VTIOC|109)
+
+enum { VT_AUTO = 0, VT_PROCESS };
+#endif
+
 /* Device to open as xf86Info.consoleFd */
 static char consoleDev[PATH_MAX] = "/dev/fb";
 
