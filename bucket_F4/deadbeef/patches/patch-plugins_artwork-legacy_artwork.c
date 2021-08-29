--- plugins/artwork-legacy/artwork.c.orig	2020-06-28 13:41:28 UTC
+++ plugins/artwork-legacy/artwork.c
@@ -65,6 +65,10 @@
 //#define trace(...) { fprintf (stderr, __VA_ARGS__); }
 #define trace(...)
 
+#ifndef NAME_MAX
+# define NAME_MAX PATH_MAX
+#endif
+
 DB_functions_t *deadbeef;
 static DB_artwork_plugin_t plugin;
 
