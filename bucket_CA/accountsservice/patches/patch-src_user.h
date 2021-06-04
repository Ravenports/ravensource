--- src/user.h.orig	2019-04-23 17:16:09.000000000 +0200
+++ src/user.h	2021-06-03 16:07:13.902776000 +0200
@@ -22,7 +22,9 @@
 
 #include <sys/types.h>
 #include <pwd.h>
+#ifdef HAVE_SHADOW_H
 #include <shadow.h>
+#endif
 
 #include <glib.h>
 #include <gio/gio.h>
@@ -54,9 +56,14 @@
 User *         user_new                     (Daemon        *daemon,
                                              uid_t          uid);
 
+#ifdef HAVE_SHADOW_H
 void           user_update_from_pwent       (User          *user,
                                              struct passwd *pwent,
                                              struct spwd   *spent);
+#else
+void           user_update_from_pwent       (User          *user,
+                                             struct passwd *pwent);
+#endif
 void           user_update_from_keyfile     (User          *user,
                                              GKeyFile      *keyfile);
 void           user_update_local_account_property (User          *user,
