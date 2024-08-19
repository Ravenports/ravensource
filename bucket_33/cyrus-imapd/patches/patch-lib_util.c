--- lib/util.c.orig	2024-08-16 00:24:23 UTC
+++ lib/util.c
@@ -1056,6 +1056,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
