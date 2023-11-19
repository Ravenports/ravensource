--- p11-kit/server.c.orig	2023-10-24 12:58:49 UTC
+++ p11-kit/server.c
@@ -92,6 +92,12 @@ typedef void (*sighandler_t)(int);
 #define _(x) (x)
 #endif
 
+#ifdef __sun__
+# ifndef SUN_LEN
+# define SUN_LEN(su)	(sizeof (sa_family_t) + strlen((su)->sun_path))
+# endif
+#endif
+
 typedef struct {
 	const char **tokens;
 	size_t n_tokens;
