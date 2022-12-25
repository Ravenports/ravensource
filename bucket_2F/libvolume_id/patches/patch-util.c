--- util.c.orig	2009-03-02 18:17:35 UTC
+++ util.c
@@ -28,9 +28,9 @@
 #include "libvolume_id.h"
 #include "util.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/param.h>
-#if __FreeBSD_version < 800067
+#if __FreeBSD_version < 800067 && __DragonFly_version < 200202 && __NetBSD_Version__ < 599001100
 static size_t strnlen (const char *s, size_t maxlen)
 {
 	size_t i;
