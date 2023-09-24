--- elf/mold-wrapper.c.orig	2023-09-24 03:28:19 UTC
+++ elf/mold-wrapper.c
@@ -1,6 +1,6 @@
 #define _GNU_SOURCE 1
 
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 #  include <alloca.h>
 #endif
 #include <dlfcn.h>
