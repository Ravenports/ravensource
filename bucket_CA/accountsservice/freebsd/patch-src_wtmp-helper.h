--- src/wtmp-helper.h.orig	2019-04-23 17:16:09.000000000 +0200
+++ src/wtmp-helper.h	2021-06-03 16:08:20.380212000 +0200
@@ -23,7 +23,6 @@
 
 #include <glib.h>
 #include <pwd.h>
-#include <shadow.h>
 
 const gchar *           wtmp_helper_get_path_for_monitor                (void);
 void                    wtmp_helper_update_login_frequencies            (GHashTable *users);
