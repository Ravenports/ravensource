--- spa/plugins/support/logger.c.orig	2025-03-14 10:07:06 UTC
+++ spa/plugins/support/logger.c
@@ -20,7 +20,7 @@
 #include <spa/utils/string.h>
 #include <spa/utils/ansi.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
 #elif defined(_MSC_VER)
 static inline void setlinebuf(FILE* stream) {
