--- libpkg/plugins.c.orig	2017-03-09 12:57:56 UTC
+++ libpkg/plugins.c
@@ -70,7 +70,11 @@ static int pkg_plugin_hook_exec(struct p
 void *
 pkg_plugin_func(struct pkg_plugin *p, const char *func)
 {
+#ifdef SKIP_PLUGINS
+	return NULL;
+#else
 	return (dlsym(p->lh, func));
+#endif
 }
 
 static int
@@ -265,6 +269,7 @@ pkg_plugins(struct pkg_plugin **plugin)
 int
 pkg_plugins_init(void)
 {
+#ifndef SKIP_PLUGINS
 	struct pkg_plugin *p = NULL;
 	char pluginfile[MAXPATHLEN];
 	const ucl_object_t *obj, *cur;
@@ -315,6 +320,7 @@ pkg_plugins_init(void)
 			free(p);
 		}
 	}
+#endif
 
 	return (EPKG_OK);
 }
@@ -377,6 +383,7 @@ pkg_plugin_parse(struct pkg_plugin *p)
 void
 pkg_plugins_shutdown(void)
 {
+#ifndef SKIP_PLUGINS
 	struct pkg_plugin *p = NULL;
 	int (*shutdown_func)(struct pkg_plugin *p);
 
@@ -394,6 +401,7 @@ pkg_plugins_shutdown(void)
 	 * Deallocate memory used by the plugins
 	 */
 	pkg_plugin_free();
+#endif
 
 	return;
 }
