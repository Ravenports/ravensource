--- glib/gcharset.c.orig	2023-04-21 14:46:05 UTC
+++ glib/gcharset.c
@@ -288,6 +288,11 @@ _g_get_ctype_charset (const char **chars
 
 #ifdef HAVE_LANGINFO_CODESET
   raw = nl_langinfo (CODESET);
+# if defined __NetBSD__
+  if (strcmp(raw, "646") == 0) {
+     raw = "ASCII";
+  }
+# endif
 #else
   G_LOCK (aliases);
   raw = _g_locale_charset_raw ();
