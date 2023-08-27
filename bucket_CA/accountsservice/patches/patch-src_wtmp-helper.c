--- src/wtmp-helper.c.orig	2023-08-12 19:01:30 UTC
+++ src/wtmp-helper.c
@@ -54,7 +54,11 @@ static gboolean
 wtmp_helper_start (void)
 {
 #if defined(HAVE_SETUTXDB)
+# if defined __DragonFly__
+        if (setutxdb (UTX_DB_LASTLOGX, NULL) != 0) {
+# else
         if (setutxdb (UTXDB_LOG, NULL) != 0) {
+# endif
                 return FALSE;
         }
 #elif defined(PATH_WTMP)
