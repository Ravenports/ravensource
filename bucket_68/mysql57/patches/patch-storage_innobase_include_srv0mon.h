--- storage/innobase/include/srv0mon.h.orig	2023-03-16 15:25:04 UTC
+++ storage/innobase/include/srv0mon.h
@@ -41,6 +41,10 @@ Created 12/15/2009	Jimmy Yang
 /* Required for FreeBSD so that INT64_MAX is defined. */
 #define __STDC_LIMIT_MACROS
 #endif /* __STDC_LIMIT_MACROS */
+#if defined(__DragonFly__) || defined(__NetBSD__)
+/* The hack above doen't work for this platform, stdint.h already imported */
+#include <machine/int_limits.h>
+#endif
 
 #include <stdint.h>
 
