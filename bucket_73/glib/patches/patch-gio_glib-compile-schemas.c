--- gio/glib-compile-schemas.c.orig	2017-08-07 14:58:31 UTC
+++ gio/glib-compile-schemas.c
@@ -1219,6 +1219,7 @@ parse_state_start_schema (ParseState  *s
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
@@ -1231,6 +1232,7 @@ parse_state_start_schema (ParseState  *s
       g_printerr ("%s\n", message);
       g_free (message);
     }
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);
