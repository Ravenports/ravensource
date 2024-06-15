Index: lib/libcyr_cfg.c
diff -u -p lib/libcyr_cfg.c.orig lib/libcyr_cfg.c
--- lib/libcyr_cfg.c.orig	2024-03-13 02:47:32 UTC
+++ lib/libcyr_cfg.c
@@ -52,7 +52,7 @@
 #include "xmalloc.h"
 #include "util.h"
 
-#if defined(__GNUC__) && __GNUC__ > 1
+#if defined(__GNUC__) && __GNUC__ > 1 && !defined(__INTEL_COMPILER)
 /* We can use the GCC union constructor extension */
 #define CFGVAL(t,v)     (union cyrus_config_value)((t)(v))
 #else
