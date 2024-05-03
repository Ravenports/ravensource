--- elf/mold-wrapper.c.orig	2024-05-03 01:04:55 UTC
+++ elf/mold-wrapper.c
@@ -9,7 +9,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 # include <alloca.h>
 #endif
 
