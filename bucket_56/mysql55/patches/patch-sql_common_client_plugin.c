--- sql-common/client_plugin.c.orig	2018-08-28 21:12:51 UTC
+++ sql-common/client_plugin.c
@@ -233,11 +233,13 @@ int mysql_client_plugin_init()
 {
   MYSQL mysql;
   struct st_mysql_client_plugin **builtin;
+  va_list unused;
 
   if (initialized)
     return 0;
 
   bzero(&mysql, sizeof(mysql)); /* dummy mysql for set_mysql_extended_error */
+  bzero(&unused, sizeof(unused)); /* suppress uninitialized-value warnings */
 
   pthread_mutex_init(&LOCK_load_client_plugin, MY_MUTEX_INIT_SLOW);
   init_alloc_root(&mem_root, 128, 128);
@@ -249,7 +251,7 @@ int mysql_client_plugin_init()
   pthread_mutex_lock(&LOCK_load_client_plugin);
 
   for (builtin= mysql_client_builtins; *builtin; builtin++)
-    add_plugin(&mysql, *builtin, 0, 0, 0);
+    add_plugin(&mysql, *builtin, 0, 0, unused);
 
   pthread_mutex_unlock(&LOCK_load_client_plugin);
 
@@ -293,9 +295,12 @@ struct st_mysql_client_plugin *
 mysql_client_register_plugin(MYSQL *mysql,
                              struct st_mysql_client_plugin *plugin)
 {
+  va_list unused;
   if (is_not_initialized(mysql, plugin->name))
     return NULL;
 
+  bzero(&unused, sizeof(unused)); /* suppress uninitialized-value warnings */
+
   pthread_mutex_lock(&LOCK_load_client_plugin);
 
   /* make sure the plugin wasn't loaded meanwhile */
@@ -307,7 +312,7 @@ mysql_client_register_plugin(MYSQL *mysq
     plugin= NULL;
   }
   else
-    plugin= add_plugin(mysql, plugin, 0, 0, 0);
+    plugin= add_plugin(mysql, plugin, 0, 0, unused);
 
   pthread_mutex_unlock(&LOCK_load_client_plugin);
   return plugin;
