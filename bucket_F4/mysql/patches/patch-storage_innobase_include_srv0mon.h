--- storage/innobase/include/srv0mon.h.orig	2024-12-15 20:00:33 UTC
+++ storage/innobase/include/srv0mon.h
@@ -41,6 +41,10 @@ Foundation, Inc., 51 Franklin St, Fifth
 /* Required for FreeBSD so that INT64_MAX is defined. */
 #define __STDC_LIMIT_MACROS
 #endif /* __STDC_LIMIT_MACROS */
+#ifdef __DragonFly__
+/* The hack above doen't work for dragonfly, stdint.h already imported */
+#include <machine/int_limits.h>
+#endif
 
 #include <stdint.h>
 #include <bitset>
