--- elf/mold-wrapper.c.orig	2024-08-07 03:32:13 UTC
+++ elf/mold-wrapper.c
@@ -9,7 +9,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 # include <alloca.h>
 #endif
 
