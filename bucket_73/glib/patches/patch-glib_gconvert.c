--- glib/gconvert.c.orig	2023-09-08 13:42:18 UTC
+++ glib/gconvert.c
@@ -216,6 +216,18 @@ g_iconv_open (const gchar  *to_codeset,
 	      const gchar  *from_codeset)
 {
   iconv_t cd;
+#if defined __NetBSD__
+  {
+    const char * nbsd_new_codeset;
+    const char * nbsd_old_codeset;
+
+    nbsd_new_codeset = (strcmp(to_codeset, "646")) ? to_codeset : "ASCII";
+    nbsd_old_codeset = (strcmp(from_codeset, "646")) ? from_codeset : "ASCII";
+
+   if (try_conversion (nbsd_new_codeset, nbsd_old_codeset, &cd))
+      goto out;
+  }
+#endif
   
   if (!try_conversion (to_codeset, from_codeset, &cd))
     {
