--- src/user.c.orig	2019-04-23 15:16:09 UTC
+++ src/user.c
@@ -138,9 +138,14 @@ user_reset_icon_file (User *user)
 }
 
 void
+#ifdef HAVE_SHADOW_H
 user_update_from_pwent (User          *user,
                         struct passwd *pwent,
                         struct spwd   *spent)
+#else
+user_update_from_pwent (User          *user,
+                        struct passwd *pwent)
+#endif
 {
         g_autofree gchar *real_name = NULL;
         gboolean is_system_account;
@@ -199,8 +204,10 @@ user_update_from_pwent (User          *u
         accounts_user_set_shell (ACCOUNTS_USER (user), pwent->pw_shell);
 
         passwd = NULL;
+#ifdef HAVE_SHADOW_H
         if (spent)
                 passwd = spent->sp_pwdp;
+#endif
 
         if (passwd && passwd[0] == '!') {
                 locked = TRUE;
@@ -218,6 +225,7 @@ user_update_from_pwent (User          *u
                 mode = PASSWORD_MODE_NONE;
         }
 
+#ifdef HAVE_SHADOW_H
         if (spent) {
                 if (spent->sp_lstchg == 0) {
                         mode = PASSWORD_MODE_SET_AT_LOGIN;
@@ -231,6 +239,9 @@ user_update_from_pwent (User          *u
                 user->days_after_expiration_until_lock = spent->sp_inact;
                 user->account_expiration_policy_known = TRUE;
         }
+#else
+        user->expiration_time = pwent->pw_expire;
+#endif
 
         accounts_user_set_password_mode (ACCOUNTS_USER (user), mode);
         is_system_account = !user_classify_is_human (accounts_user_get_uid (ACCOUNTS_USER (user)),
@@ -844,11 +855,11 @@ user_change_real_name_authorized_cb (Dae
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-c";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-c";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -913,11 +924,11 @@ user_change_user_name_authorized_cb (Dae
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-l";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-n";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1312,7 +1323,7 @@ user_change_home_dir_authorized_cb (Daem
 {
         gchar *home_dir = data;
         g_autoptr(GError) error = NULL;
-        const gchar *argv[7];
+        const gchar *argv[6];
 
         if (g_strcmp0 (accounts_user_get_home_directory (ACCOUNTS_USER (user)), home_dir) != 0) {
                 sys_log (context,
@@ -1321,13 +1332,12 @@ user_change_home_dir_authorized_cb (Daem
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          home_dir);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-m";
-                argv[2] = "-d";
-                argv[3] = home_dir;
-                argv[4] = "--";
-                argv[5] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                argv[6] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "-d";
+                argv[2] = home_dir;
+                argv[3] = "-n";
+                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1378,11 +1388,11 @@ user_change_shell_authorized_cb (Daemon
                          accounts_user_get_uid (ACCOUNTS_USER (user)),
                          shell);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-s";
-                argv[2] = shell;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-s";
+                argv[4] = shell;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1593,7 +1603,7 @@ user_change_locked_authorized_cb (Daemon
 {
         gboolean locked = GPOINTER_TO_INT (data);
         g_autoptr(GError) error = NULL;
-        const gchar *argv[5];
+        const gchar *argv[4];
 
         if (accounts_user_get_locked (ACCOUNTS_USER (user)) != locked) {
                 sys_log (context,
@@ -1601,11 +1611,10 @@ user_change_locked_authorized_cb (Daemon
                          locked ? "locking" : "unlocking",
                          accounts_user_get_user_name (ACCOUNTS_USER (user)),
                          accounts_user_get_uid (ACCOUNTS_USER (user)));
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = locked ? "-L" : "-U";
-                argv[2] = "--";
-                argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                argv[4] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = locked ? "lock" : "unlock";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1726,11 +1735,11 @@ user_change_account_type_authorized_cb (
 
                 g_free (groups);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-G";
-                argv[2] = str->str;
-                argv[3] = "--";
-                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                argv[3] = "-G";
+                argv[4] = str->str;
                 argv[5] = NULL;
 
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1780,7 +1789,7 @@ user_change_password_mode_authorized_cb
 {
         PasswordMode mode = GPOINTER_TO_INT (data);
         g_autoptr(GError) error = NULL;
-        const gchar *argv[6];
+        const gchar *argv[5];
 
         if (((PasswordMode) accounts_user_get_password_mode (ACCOUNTS_USER (user))) != mode) {
                 sys_log (context,
@@ -1795,10 +1804,8 @@ user_change_password_mode_authorized_cb
                     mode == PASSWORD_MODE_NONE) {
 
                         argv[0] = "/usr/bin/passwd";
-                        argv[1] = "-d";
-                        argv[2] = "--";
-                        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                        argv[4] = NULL;
+                        argv[1] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                        argv[2] = NULL;
 
                         if (!spawn_with_login_uid (context, argv, &error)) {
                                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1806,12 +1813,11 @@ user_change_password_mode_authorized_cb
                         }
 
                         if (mode == PASSWORD_MODE_SET_AT_LOGIN) {
-                                argv[0] = "/usr/bin/chage";
-                                argv[1] = "-d";
+                                argv[0] = "/usr/bin/chpass";
+                                argv[1] = "-e";
                                 argv[2] = "0";
-                                argv[3] = "--";
-                                argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                                argv[5] = NULL;
+                                argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                                argv[4] = NULL;
 
                                 if (!spawn_with_login_uid (context, argv, &error)) {
                                         throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1827,11 +1833,10 @@ user_change_password_mode_authorized_cb
                         accounts_user_set_locked (ACCOUNTS_USER (user), FALSE);
                 }
                 else if (accounts_user_get_locked (ACCOUNTS_USER (user))) {
-                        argv[0] = "/usr/sbin/usermod";
-                        argv[1] = "-U";
-                        argv[2] = "--";
-                        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-                        argv[4] = NULL;
+                        argv[0] = "/usr/sbin/pw";
+                        argv[1] = "unlock";
+                        argv[2] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+                        argv[3] = NULL;
 
                         if (!spawn_with_login_uid (context, argv, &error)) {
                                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
@@ -1896,7 +1901,7 @@ user_change_password_authorized_cb (Daem
 {
         gchar **strings = data;
         g_autoptr(GError) error = NULL;
-        const gchar *argv[6];
+        const gchar *argv[5];
 
         sys_log (context,
                  "set password and hint of user '%s' (%d)",
@@ -1905,12 +1910,11 @@ user_change_password_authorized_cb (Daem
 
         g_object_freeze_notify (G_OBJECT (user));
 
-        argv[0] = "/usr/sbin/usermod";
+        argv[0] = "/usr/sbin/chpass";
         argv[1] = "-p";
         argv[2] = strings[0];
-        argv[3] = "--";
-        argv[4] = accounts_user_get_user_name (ACCOUNTS_USER (user));
-        argv[5] = NULL;
+        argv[3] = accounts_user_get_user_name (ACCOUNTS_USER (user));
+        argv[4] = NULL;
 
         if (!spawn_with_login_uid (context, argv, &error)) {
                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
