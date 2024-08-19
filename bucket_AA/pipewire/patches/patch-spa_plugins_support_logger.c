--- spa/plugins/support/logger.c.orig	2024-07-31 10:02:24 UTC
+++ spa/plugins/support/logger.c
@@ -20,7 +20,7 @@
 #include <spa/utils/string.h>
 #include <spa/utils/ansi.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
 #define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
 #endif
 
