--- src/java.base/unix/native/libjava/path_util.c.orig	2023-10-15 00:46:12 UTC
+++ src/java.base/unix/native/libjava/path_util.c
@@ -122,7 +122,7 @@ collapse(char *path)
 
     nc = collapsible(names);
     if (nc < 2) return;         /* Nothing to do */
-    ix = (char **)alloca(nc * sizeof(char *));
+    ix = (char **)__builtin_alloca(nc * sizeof(char *));
     splitNames(names, ix);
 
     for (i = 0; i < nc; i++) {
