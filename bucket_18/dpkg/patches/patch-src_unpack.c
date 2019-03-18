--- src/unpack.c.orig	2019-02-23 14:26:43 UTC
+++ src/unpack.c
@@ -164,7 +164,15 @@ get_control_dir(char *cidir)
   if (f_noact) {
     char *tmpdir;
 
+#ifdef __sun__
+    tmpdir = mktemp(path_make_temp_template("dpkg"));
+    if (tmpdir != NULL) {
+       if (mkdir(tmpdir, 0700) != 0)
+          ohshite(_("unable to create temporary directory")); 
+    }
+#else
     tmpdir = mkdtemp(path_make_temp_template("dpkg"));
+#endif
     if (tmpdir == NULL)
       ohshite(_("unable to create temporary directory"));
 
