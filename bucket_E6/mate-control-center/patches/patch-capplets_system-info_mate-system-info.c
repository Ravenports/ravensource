--- capplets/system-info/mate-system-info.c.orig	2024-09-01 13:29:20.266268000 +0200
+++ capplets/system-info/mate-system-info.c	2024-09-01 13:49:14.719347000 +0200
@@ -131,13 +131,15 @@
 mate_system_info_set_row (MateSystemInfo *info)
 {
     mate_system_info_row_fill (info->hostname_row, _("Device Name"), FALSE);
+#ifdef HAVE_SYSTEMD
     mate_system_info_row_fill (info->hardware_model_row, _("Hardware Model"), TRUE);
+    mate_system_info_row_fill (info->virtualization_row, _("Virtualization"), TRUE);
+#endif
     mate_system_info_row_fill (info->memory_row, _("Memory"), TRUE);
     mate_system_info_row_fill (info->processor_row, _("Processor"), TRUE);
     mate_system_info_row_fill (info->graphics_row, _("Graphics"), TRUE);
     mate_system_info_row_fill (info->disk_row, _("Disk Capacity"), FALSE);
     mate_system_info_row_fill (info->kernel_row, _("Kernel Version"), FALSE);
-    mate_system_info_row_fill (info->virtualization_row, _("Virtualization"), TRUE);
     mate_system_info_row_fill (info->windowing_system_row, _("Windowing System"), TRUE);
     mate_system_info_row_fill (info->mate_version_row, _("MATE Version"), TRUE);
     mate_system_info_row_fill (info->os_name_row, _("OS Name"), TRUE);
@@ -160,6 +162,7 @@
 get_system_hostname (void)
 {
     GDBusProxy         *hostnamed_proxy;
+#ifdef HAVE_SYSTEMD
     g_autoptr(GVariant) variant = NULL;
     g_autoptr(GError)   error = NULL; 
 
@@ -206,8 +209,12 @@
         g_object_unref (hostnamed_proxy);
         return g_variant_dup_string (variant, NULL);
     }
+#else
+    return g_strdup (g_get_host_name ());
+#endif
 }
 
+#ifdef HAVE_SYSTEMD
 static char *
 get_hardware_model (void)
 {
@@ -258,6 +265,7 @@
 
     return NULL;
 }
+#endif
 
 static char *
 get_cpu_info (void)
@@ -478,6 +486,7 @@
     return g_strdup_printf ("%s %s", un.sysname, un.release);
 }
 
+#ifdef HAVE_SYSTEMD
 static struct {
     const char *id;
     const char *display;
@@ -560,6 +569,7 @@
 
     return get_virtualization_label (g_variant_get_string (inner, NULL));
 }
+#endif
 
 static char *
 get_mate_desktop_version ()
@@ -615,7 +625,10 @@
 {
     g_autofree char *logo_name = NULL;
     g_autofree char *hostname_text = NULL;
+#ifdef HAVE_SYSTEMD
     g_autofree char *hw_model_text = NULL;
+    g_autofree char *virt_text = NULL;
+#endif
     g_autofree char *memory_text = NULL;
     g_autofree char *cpu_text = NULL;
     g_autofree char *os_type_text = NULL;
@@ -623,7 +636,6 @@
     g_autofree char *disk_text = NULL;
     g_autofree char *kernel_text = NULL;
     g_autofree char *windowing_system_text = NULL;
-    g_autofree char *virt_text = NULL;
     g_autofree char *de_text = NULL;
     g_autofree char *graphics_hardware_string = NULL;
 
@@ -638,6 +650,7 @@
     label = g_object_get_data (G_OBJECT (info->hostname_row), "labelvalue");
     set_lable_style (label, "gray", 12, hostname_text, FALSE);
 
+#ifdef HAVE_SYSTEMD
     hw_model_text = get_hardware_model ();
     if (hw_model_text != NULL)
     {
@@ -645,6 +658,7 @@
         label = g_object_get_data (G_OBJECT (info->hardware_model_row), "labelvalue");
         set_lable_style (label, "gray", 12, hw_model_text, FALSE);
     }
+#endif
 
     glibtop_get_mem (&mem);
     memory_text = g_format_size_full (mem.total, G_FORMAT_SIZE_IEC_UNITS);
@@ -667,6 +681,7 @@
     label = g_object_get_data (G_OBJECT (info->kernel_row), "labelvalue");
     set_lable_style (label, "gray", 12, kernel_text, FALSE);
 
+#ifdef HAVE_SYSTEMD
     virt_text = get_system_virt ();
     if (virt_text != NULL)
     {
@@ -674,6 +689,7 @@
         label = g_object_get_data (G_OBJECT (info->virtualization_row), "labelvalue");
         set_lable_style (label, "gray", 12, virt_text, FALSE);
     }
+#endif
     windowing_system_text = get_windowing_system ();
     label = g_object_get_data (G_OBJECT (info->windowing_system_row), "labelvalue");
     set_lable_style (label, "gray", 12, windowing_system_text, FALSE);
@@ -706,7 +722,10 @@
     gtk_widget_class_set_template_from_resource (widget_class, "/org/mate/control-center/system-info/mate-system-info.ui");
 
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, hostname_row);
+#ifdef HAVE_SYSTEMD
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, hardware_box);
+    gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, virtualization_row);
+# endif
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, disk_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, mate_version_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, graphics_row);
@@ -717,7 +736,6 @@
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, os_name_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, os_type_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, processor_row);
-    gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, virtualization_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, kernel_row);
     gtk_widget_class_bind_template_child (widget_class, MateSystemInfo, windowing_system_row);
 }
