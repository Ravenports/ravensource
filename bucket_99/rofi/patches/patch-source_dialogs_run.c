--- source/dialogs/run.c.orig	2021-08-29 09:11:37 UTC
+++ source/dialogs/run.c
@@ -45,6 +45,9 @@
 #include <strings.h>
 #include <sys/types.h>
 #include <unistd.h>
+#ifdef __sun__
+#include <sys/stat.h>
+#endif
 
 #include "dialogs/filebrowser.h"
 #include "dialogs/run.h"
@@ -232,6 +235,9 @@ static RunEntry *get_apps(unsigned int *
   RunEntry *retv = NULL;
   unsigned int num_favorites = 0;
   char *path;
+#ifdef __sun__
+  struct stat  s;
+#endif
 
   if (g_getenv("PATH") == NULL) {
     return NULL;
@@ -287,8 +293,13 @@ static RunEntry *get_apps(unsigned int *
       g_free(dirn);
 
       while ((dent = readdir(dir)) != NULL) {
+#ifdef __sun__
+        stat(dent->d_name, &s);
+        if (s.st_mode != S_IFREG && s.st_mode != S_IFLNK && s.st_mode != 0) {
+#else
         if (dent->d_type != DT_REG && dent->d_type != DT_LNK &&
             dent->d_type != DT_UNKNOWN) {
+#endif
           continue;
         }
         // Skip dot files.
