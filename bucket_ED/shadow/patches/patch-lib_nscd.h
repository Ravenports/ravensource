--- lib/nscd.h.orig	2026-09-23 14:27:40 UTC
+++ lib/nscd.h
@@ -8,7 +8,7 @@
 extern int nscd_flush_cache (const char *service);
 #else
 static inline int
-nscd_flush_cache(MAYBE_UNUSED int _1)
+nscd_flush_cache(MAYBE_UNUSED const char* _1)
 {
 	return 0;
 }
