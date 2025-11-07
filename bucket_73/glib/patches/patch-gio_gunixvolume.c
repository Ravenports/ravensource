--- gio/gunixvolume.c.orig	2025-10-21 14:26:53 UTC
+++ gio/gunixvolume.c
@@ -369,9 +369,14 @@ g_unix_volume_eject (GVolume
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  const gchar *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+  argv[2] = unix_volume->device_path;
+#else
   const gchar *argv[] = { "eject", NULL, NULL };
 
   argv[1] = unix_volume->device_path;
+#endif
 
   eject_mount_do (volume, cancellable, callback, user_data, argv, "[gio] eject volume");
 }
