--- lib/util.c.orig	2026-03-29 22:54:00 UTC
+++ lib/util.c
@@ -83,6 +83,9 @@
 #include "zlib.h"
 #endif
 
+#ifndef LOG_PRI
+#define LOG_PRI(p) ((p) & LOG_PRIMASK)
+#endif
 
 #define BEAUTYBUFSIZE 4096
 
@@ -1056,6 +1059,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
