--- src/tools/pw-cli.c.orig	2024-07-31 10:02:24 UTC
+++ src/tools/pw-cli.c
@@ -10,7 +10,7 @@
 #include <signal.h>
 #include <string.h>
 #include <ctype.h>
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__)
+#if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
 #endif
 #include <getopt.h>
