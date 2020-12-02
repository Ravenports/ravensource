--- lib/util.c.orig	2020-11-29 23:52:48 UTC
+++ lib/util.c
@@ -1002,6 +1002,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
