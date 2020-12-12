--- p11-kit/server.c.orig	2020-12-11 14:48:46 UTC
+++ p11-kit/server.c
@@ -84,6 +84,12 @@ typedef void (*sighandler_t)(int);
 
 #endif /* OS_UNIX */
 
+#ifdef __sun__
+# ifndef SUN_LEN
+# define SUN_LEN(su)	(sizeof (sa_family_t) + strlen((su)->sun_path))
+# endif
+#endif
+
 typedef struct {
 	const char **tokens;
 	size_t n_tokens;
