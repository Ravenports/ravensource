--- src/evdev/input.c.orig	2025-02-02 22:46:39 UTC
+++ src/evdev/input.c
@@ -18,7 +18,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if 0
 #include <dev/evdev/input.h>
 #else
 #include <linux/input.h>
