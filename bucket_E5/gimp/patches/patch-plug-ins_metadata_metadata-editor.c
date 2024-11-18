--- plug-ins/metadata/metadata-editor.c.orig	2024-05-03 00:33:35 UTC
+++ plug-ins/metadata/metadata-editor.c
@@ -2140,7 +2140,7 @@ metadata_dialog_editor_set_metadata (GEx
                             }
                           else
                             {
-                              if (! g_strv_contains (values, equiv_values[evi]))
+                              if (! g_strv_contains ((const gchar * const*)values, equiv_values[evi]))
                                 {
                                   gchar *tmpvalue;
 
