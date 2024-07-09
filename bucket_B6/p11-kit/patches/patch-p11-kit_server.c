--- p11-kit/server.c.orig	2024-07-01 13:53:16 UTC
+++ p11-kit/server.c
@@ -93,6 +93,12 @@ typedef void (*sighandler_t)(int);
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
