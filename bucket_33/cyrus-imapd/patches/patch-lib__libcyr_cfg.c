Index: lib/libcyr_cfg.c
diff -u -p lib/libcyr_cfg.c.orig lib/libcyr_cfg.c
--- lib/libcyr_cfg.c.orig	2020-08-24 03:32:43 UTC
+++ lib/libcyr_cfg.c
@@ -50,7 +50,7 @@
 #include "libcyr_cfg.h"
 #include "cyrusdb.h"
 
-#if defined(__GNUC__) && __GNUC__ > 1
+#if defined(__GNUC__) && __GNUC__ > 1 && !defined(__INTEL_COMPILER)
 /* We can use the GCC union constructor extension */
 #define CFGVAL(t,v)     (union cyrus_config_value)((t)(v))
 #else
