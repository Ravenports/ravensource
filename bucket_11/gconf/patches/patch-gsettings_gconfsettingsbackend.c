--- gsettings/gconfsettingsbackend.c.orig	2011-08-16 02:59:31 UTC
+++ gsettings/gconfsettingsbackend.c
@@ -924,5 +924,5 @@ gconf_settings_backend_register (GIOModu
   g_io_extension_point_implement (G_SETTINGS_BACKEND_EXTENSION_POINT_NAME,
                                   GCONF_TYPE_SETTINGS_BACKEND,
                                   "gconf",
-                                  -1);
+                                  10);
 }
