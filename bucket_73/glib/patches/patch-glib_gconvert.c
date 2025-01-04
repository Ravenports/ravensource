--- glib/gconvert.c.orig	2024-12-11 22:21:22 UTC
+++ glib/gconvert.c
@@ -74,7 +74,7 @@ try_conversion (const char *to_codeset,
   if (*cd == (iconv_t)-1 && errno == EINVAL)
     return FALSE;
 
-#if defined(__FreeBSD__) && defined(ICONV_SET_ILSEQ_INVALID)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(ICONV_SET_ILSEQ_INVALID)
   /* On FreeBSD request GNU iconv compatible handling of characters that cannot
    * be represented in the destination character set.
    * See https://cgit.freebsd.org/src/commit/?id=7c5b23111c5fd1992047922d4247c4a1ce1bb6c3
@@ -126,6 +126,18 @@ g_iconv_open (const gchar  *to_codeset,
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
