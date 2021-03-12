--- lib/util.c.orig	2021-03-09 04:32:13 UTC
+++ lib/util.c
@@ -1002,6 +1002,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
