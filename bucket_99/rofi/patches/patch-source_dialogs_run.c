--- source/dialogs/run.c.orig	2019-07-01 12:29:09 UTC
+++ source/dialogs/run.c
@@ -45,6 +45,9 @@
 #include <strings.h>
 #include <string.h>
 #include <errno.h>
+#ifdef __sun__
+#include <sys/stat.h>
+#endif
 
 #include "rofi.h"
 #include "settings.h"
@@ -209,6 +212,9 @@ static char ** get_apps ( unsigned int *
     char         **retv        = NULL;
     unsigned int num_favorites = 0;
     char         *path;
+#ifdef __sun__
+    struct stat  s;
+#endif
 
     if ( g_getenv ( "PATH" ) == NULL ) {
         return NULL;
@@ -253,7 +259,12 @@ static char ** get_apps ( unsigned int *
             g_free ( dirn );
 
             while ( ( dent = readdir ( dir ) ) != NULL ) {
+#ifdef __sun__
+                stat(dent->d_name, &s);
+                if (s.st_mode != S_IFREG && s.st_mode != S_IFLNK && s.st_mode != 0) {
+#else
                 if ( dent->d_type != DT_REG && dent->d_type != DT_LNK && dent->d_type != DT_UNKNOWN ) {
+#endif
                     continue;
                 }
                 // Skip dot files.
