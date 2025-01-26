--- evdev/uinput.c.orig	2024-05-07 22:20:05 UTC
+++ evdev/uinput.c
@@ -8,7 +8,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && !defined(__MidnightBSD__)
 #include <dev/evdev/input.h>
 #include <dev/evdev/uinput.h>
 #else
