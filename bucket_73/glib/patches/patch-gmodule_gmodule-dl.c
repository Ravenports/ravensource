--- gmodule/gmodule-dl.c.orig	2020-10-19 15:05:31 UTC
+++ gmodule/gmodule-dl.c
@@ -106,6 +106,7 @@ _g_module_open (const gchar *file_name,
 static gpointer
 _g_module_self (void)
 {
+#if ! defined(__FreeBSD__) && ! defined(__DragonFly__)
   gpointer handle;
   
   /* to query symbols from the program itself, special link options
@@ -128,6 +129,9 @@ _g_module_self (void)
     g_module_set_error (fetch_dlerror (TRUE));
   
   return handle;
+#else
+  return RTLD_DEFAULT;
+#endif
 }
 
 static void
