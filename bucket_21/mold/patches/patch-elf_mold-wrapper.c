--- elf/mold-wrapper.c.orig	2024-03-01 02:30:05 UTC
+++ elf/mold-wrapper.c
@@ -1,6 +1,6 @@
 #define _GNU_SOURCE 1
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 #  include <alloca.h>
 #endif
 #include <dlfcn.h>
