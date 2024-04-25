--- src/kb/config.S.orig	2023-09-20 18:37:15 UTC
+++ src/kb/config.S
@@ -7,7 +7,10 @@
 #ifdef __APPLE__
 .section __TEXT,__const
 #else
-#ifdef __linux__
+#if defined __linux__ \
+ || defined __NetBSD__ \
+ || defined __FreeBSD__ \
+ || defined __DragonFly__
 .section .note.GNU-stack
 #endif
 .section .rodata
