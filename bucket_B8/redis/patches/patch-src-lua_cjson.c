--- deps/lua/src/lua_cjson.c.orig	2026-02-08 07:03:30 UTC
+++ deps/lua/src/lua_cjson.c
@@ -47,7 +47,9 @@
 #include "strbuf.h"
 #include "fpconv.h"
 
+#if defined(__sun)
 #include "../../../src/solarisfixes.h"
+#endif
 
 #ifndef CJSON_MODNAME
 #define CJSON_MODNAME   "cjson"
