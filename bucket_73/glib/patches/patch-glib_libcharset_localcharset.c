--- glib/libcharset/localcharset.c.orig	2025-02-20 13:08:16 UTC
+++ glib/libcharset/localcharset.c
@@ -287,6 +287,12 @@ _g_locale_charset_raw (void)
 
   /* Most systems support nl_langinfo (CODESET) nowadays.  */
   codeset = nl_langinfo (CODESET);
+# if defined(__NetBSD__)
+  /* If "646" is returned on NetBSD iconv cannot convert it so override. */
+  if (strcmp(codeset, "646") == 0) {
+     codeset = "ASCII";
+  }
+# endif
 
 #  ifdef __CYGWIN__
   /* Cygwin 2006 does not have locales.  nl_langinfo (CODESET) always
