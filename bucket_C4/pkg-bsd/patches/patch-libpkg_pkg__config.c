--- libpkg/pkg_config.c.orig	2017-03-09 12:57:56 UTC
+++ libpkg/pkg_config.c
@@ -497,6 +497,9 @@ pkg_config_dump(void)
 static void
 disable_plugins_if_static(void)
 {
+#ifdef SKIP_PLUGINS
+	ucl_object_replace_key(config, ucl_object_frombool(false), "PKG_ENABLE_PLUGINS", 18, false);
+#else
 	void *dlh;
 
 	dlh = dlopen(0, RTLD_NOW);
@@ -507,6 +510,7 @@ disable_plugins_if_static(void)
 	else
 		dlclose(dlh);
 
+#endif
 	return;
 }
 
