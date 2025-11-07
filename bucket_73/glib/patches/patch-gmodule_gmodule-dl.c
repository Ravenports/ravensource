--- gmodule/gmodule-dl.c.orig	2025-10-21 14:26:53 UTC
+++ gmodule/gmodule-dl.c
@@ -153,6 +153,7 @@ _g_module_open (const gchar *file_name,
 static gpointer
 _g_module_self (void)
 {
+#if ! defined(__FreeBSD__) && ! defined(__DragonFly__)
   gpointer handle;
   
   /* to query symbols from the program itself, special link options
@@ -177,6 +178,9 @@ _g_module_self (void)
   unlock_dlerror ();
   
   return handle;
+#else
+  return RTLD_DEFAULT;
+#endif
 }
 
 static void
