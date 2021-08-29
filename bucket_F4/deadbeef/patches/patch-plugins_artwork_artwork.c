--- plugins/artwork/artwork.c.orig	2020-06-28 13:41:28 UTC
+++ plugins/artwork/artwork.c
@@ -72,6 +72,10 @@
 
 #define trace(...) { deadbeef->log_detailed (&plugin.plugin.plugin, 0, __VA_ARGS__); }
 
+#ifndef NAME_MAX
+# define NAME_MAX PATH_MAX
+#endif
+
 DB_functions_t *deadbeef;
 static ddb_artwork_plugin_t plugin;
 
