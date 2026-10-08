Index: lib/libcyr_cfg.c
diff -u -p lib/libcyr_cfg.c.orig lib/libcyr_cfg.c
--- lib/libcyr_cfg.c.orig	2026-09-09 01:06:41 UTC
+++ lib/libcyr_cfg.c
@@ -53,7 +53,7 @@
 #include "xmalloc.h"
 #include "util.h"
 
-#if defined(__GNUC__) && __GNUC__ > 1
+#if defined(__GNUC__) && __GNUC__ > 1 && !defined(__INTEL_COMPILER)
 /* We can use the GCC union constructor extension */
 #define CFGVAL(t,v)     (union cyrus_config_value)((t)(v))
 #else
