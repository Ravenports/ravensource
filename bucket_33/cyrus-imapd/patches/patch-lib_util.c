--- lib/util.c.orig	2023-02-12 22:29:57 UTC
+++ lib/util.c
@@ -1045,6 +1045,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
