--- common/gvfsutils.h.orig	2026-07-31 07:36:54 UTC
+++ common/gvfsutils.h
@@ -38,7 +38,11 @@ gvfs_free_password (gpointer str)
 {
   if (str != NULL)
     {
+#if defined(__NetBSD__)
+      explicit_memset (str, 0, strlen (str));
+#else
       explicit_bzero (str, strlen (str));
+#endif
       g_free (str);
     }
 }
