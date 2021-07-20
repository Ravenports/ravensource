--- src/wtmp-helper.c.orig	2019-04-23 15:16:09 UTC
+++ src/wtmp-helper.c
@@ -51,7 +51,7 @@ user_previous_login_free (UserPreviousLo
 static gboolean
 wtmp_helper_start (void)
 {
-#if defined(HAVE_SETUTXDB)
+#if defined(HAVE_SETUTXDB) && !defined(__DragonFly__)
                 if (setutxdb (UTXDB_LOG, NULL) != 0) {
                         return FALSE;
                 }
