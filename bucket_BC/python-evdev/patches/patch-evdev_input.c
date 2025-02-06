--- evdev/input.c.orig	2024-01-28 21:31:33 UTC
+++ evdev/input.c
@@ -18,7 +18,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if 0
 #include <dev/evdev/input.h>
 #else
 #include <linux/input.h>
