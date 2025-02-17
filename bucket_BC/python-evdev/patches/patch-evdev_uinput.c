--- src/evdev/uinput.c.orig	2025-02-02 20:25:21 UTC
+++ src/evdev/uinput.c
@@ -8,7 +8,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if 0
 #include <dev/evdev/input.h>
 #include <dev/evdev/uinput.h>
 #else
