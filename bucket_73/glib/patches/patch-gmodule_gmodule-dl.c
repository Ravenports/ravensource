--- gmodule/gmodule-dl.c.orig	2026-05-02 12:26:52 UTC
+++ gmodule/gmodule-dl.c
@@ -166,6 +166,7 @@ _g_module_open (const gchar *file_name,
 static gpointer
 _g_module_self (void)
 {
+#if ! defined(__FreeBSD__) && ! defined(__DragonFly__)
   gpointer handle;
   
   /* to query symbols from the program itself, special link options
@@ -190,6 +191,9 @@ _g_module_self (void)
   unlock_dlerror ();
   
   return handle;
+#else
+  return RTLD_DEFAULT;
+#endif
 }
 
 static void
