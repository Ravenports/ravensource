--- src/tools/pw-cli.c.orig	2024-10-23 07:44:10 UTC
+++ src/tools/pw-cli.c
@@ -10,7 +10,7 @@
 #include <signal.h>
 #include <string.h>
 #include <ctype.h>
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__)
+#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <getopt.h>
