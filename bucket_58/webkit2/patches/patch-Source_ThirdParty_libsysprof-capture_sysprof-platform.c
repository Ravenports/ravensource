--- Source/ThirdParty/libsysprof-capture/sysprof-platform.c.orig	2025-02-25 08:25:38 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-platform.c
@@ -129,6 +129,14 @@ sysprof_memfd_create (const char *name)
 
   snprintf (template, template_len, "%s/sysprof-XXXXXX", tmpdir);
 
+#ifndef O_BINARY
+#define O_BINARY	0
+#endif
+
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 #ifdef __APPLE__
   flags = 0;
 #else
