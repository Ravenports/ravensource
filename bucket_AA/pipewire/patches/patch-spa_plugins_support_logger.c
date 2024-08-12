--- spa/plugins/support/logger.c.orig	2024-02-02 13:09:07 UTC
+++ spa/plugins/support/logger.c
@@ -22,7 +22,7 @@
 
 #include "log-patterns.h"
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__)
 #define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
 #endif
 
