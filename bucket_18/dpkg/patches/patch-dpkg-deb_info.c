--- dpkg-deb/info.c.orig	2019-01-23 21:36:34 UTC
+++ dpkg-deb/info.c
@@ -66,7 +66,15 @@ static void info_prepare(const char *con
   *debarp= *(*argvp)++;
   if (!*debarp) badusage(_("--%s needs a .deb filename argument"),cipaction->olong);
 
+#ifdef __sun__
+  dbuf = mktemp(path_make_temp_template("dpkg-deb"));
+  if (dbuf != NULL) {
+    if (mkdir(dbuf, 0700) != 0)
+      ohshite(_("unable to create temporary directory"));
+  }
+#else
   dbuf = mkdtemp(path_make_temp_template("dpkg-deb"));
+#endif
   if (!dbuf)
     ohshite(_("unable to create temporary directory"));
   *dirp = dbuf;
