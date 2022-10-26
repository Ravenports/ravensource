--- gio/glib-compile-schemas.c.orig	2022-10-25 12:53:22 UTC
+++ gio/glib-compile-schemas.c
@@ -1234,6 +1234,7 @@ parse_state_start_schema (ParseState  *s
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
@@ -1246,6 +1247,7 @@ parse_state_start_schema (ParseState  *s
       g_printerr ("%s\n", message);
       g_free (message);
     }
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);
