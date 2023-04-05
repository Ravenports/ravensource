--- src/daemon.c.orig	2019-04-23 15:16:09 UTC
+++ src/daemon.c
@@ -81,7 +81,11 @@ typedef struct {
         GHashTable *extension_ifaces;
 } DaemonPrivate;
 
+#ifdef HAVE_SHADOW_H
 typedef struct passwd * (* EntryGeneratorFunc) (Daemon *, GHashTable *, gpointer *, struct spwd **shadow_entry);
+#else
+typedef struct passwd * (* EntryGeneratorFunc) (Daemon *, GHashTable *, gpointer *);
+#endif
 
 typedef struct {
         Daemon *daemon;
@@ -165,17 +169,25 @@ remove_cache_files (const gchar *user_na
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_fgetpwent (Daemon       *daemon,
                            GHashTable   *users,
                            gpointer     *state,
                            struct spwd **spent)
+#else
+entry_generator_fgetpwent (Daemon       *daemon,
+                           GHashTable   *users,
+                           gpointer     *state)
+#endif
 {
         struct passwd *pwent;
 
+#ifdef HAVE_SHADOW_H
         struct {
                 struct spwd spbuf;
                 char buf[1024];
         } *shadow_entry_buffers;
+#endif
 
         struct {
                 FILE *fp;
@@ -186,6 +198,7 @@ entry_generator_fgetpwent (Daemon
         if (*state == NULL) {
                 GHashTable *shadow_users = NULL;
                 FILE *fp;
+#ifdef HAVE_SHADOW_H
                 struct spwd *shadow_entry;
 
                 fp = fopen (PATH_SHADOW, "r");
@@ -219,6 +232,7 @@ entry_generator_fgetpwent (Daemon
                         g_clear_pointer (&shadow_users, g_hash_table_unref);
                         return NULL;
                 }
+#endif
 
                 fp = fopen (PATH_PASSWD, "r");
                 if (fp == NULL) {
@@ -240,12 +254,17 @@ entry_generator_fgetpwent (Daemon
         if (g_hash_table_size (users) < MAX_LOCAL_USERS) {
                 pwent = fgetpwent (generator_state->fp);
                 if (pwent != NULL) {
+#ifdef HAVE_SHADOW_H
                         shadow_entry_buffers = g_hash_table_lookup (generator_state->users, pwent->pw_name);
 
                         if (shadow_entry_buffers != NULL) {
                             *spent = &shadow_entry_buffers->spbuf;
                         }
                         return pwent;
+#else
+                        if (!generator_state->users || g_hash_table_lookup (generator_state->users, pwent->pw_name))
+                            return pwent;
+#endif
                 }
         }
 
@@ -259,10 +278,16 @@ entry_generator_fgetpwent (Daemon
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_cachedir (Daemon       *daemon,
                           GHashTable   *users,
                           gpointer     *state,
                           struct spwd **shadow_entry)
+#else
+entry_generator_cachedir (Daemon       *daemon,
+                          GHashTable   *users,
+                          gpointer     *state)
+#endif
 {
         struct passwd *pwent;
         g_autoptr(GError) error = NULL;
@@ -304,7 +329,9 @@ entry_generator_cachedir (Daemon       *
                         errno = 0;
                         pwent = getpwnam (name);
                         if (pwent != NULL) {
+#ifdef HAVE_SHADOW_H
                                 *shadow_entry = getspnam (pwent->pw_name);
+#endif
 
                                 return pwent;
                         } else if (errno == 0) {
@@ -340,10 +367,16 @@ entry_generator_cachedir (Daemon       *
 }
 
 static struct passwd *
+#ifdef HAVE_SHADOW_H
 entry_generator_requested_users (Daemon       *daemon,
                                  GHashTable   *users,
                                  gpointer     *state,
                                  struct spwd **shadow_entry)
+#else
+entry_generator_requested_users (Daemon       *daemon,
+                                 GHashTable   *users,
+                                 gpointer     *state)
+#endif
 {
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         struct passwd *pwent;
@@ -371,7 +404,9 @@ entry_generator_requested_users (Daemon
                                 if (pwent == NULL) {
                                         g_debug ("user '%s' requested previously but not present on system", name);
                                 } else {
+#ifdef HAVE_SHADOW_H
                                         *shadow_entry = getspnam (pwent->pw_name);
+#endif
 
                                         return pwent;
                                 }
@@ -394,19 +429,29 @@ load_entries (Daemon             *daemon
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         gpointer generator_state = NULL;
         struct passwd *pwent;
+#ifdef HAVE_SHADOW_H
         struct spwd *spent = NULL;
+#endif
         User *user = NULL;
 
         g_assert (entry_generator != NULL);
 
         for (;;) {
+#ifdef HAVE_SHADOW_H
                 spent = NULL;
                 pwent = entry_generator (daemon, users, &generator_state, &spent);
+#else
+                pwent = entry_generator (daemon, users, &generator_state);
+#endif
                 if (pwent == NULL)
                         break;
 
                 /* Skip system users... */
+#ifdef HAVE_SHADOW_H
                 if (!explicitly_requested && !user_classify_is_human (pwent->pw_uid, pwent->pw_name, pwent->pw_shell, spent? spent->sp_pwdp : NULL)) {
+#else
+                if (!explicitly_requested && !user_classify_is_human (pwent->pw_uid, pwent->pw_name, pwent->pw_shell, NULL)) {
+#endif
                         g_debug ("skipping user: %s", pwent->pw_name);
                         continue;
                 }
@@ -428,7 +473,11 @@ load_entries (Daemon             *daemon
 
                         /* freeze & update users not already in the new list */
                         g_object_freeze_notify (G_OBJECT (user));
+#ifdef HAVE_SHADOW_H
                         user_update_from_pwent (user, pwent, spent);
+#else
+                        user_update_from_pwent (user, pwent);
+#endif
 
                         g_hash_table_insert (users, g_strdup (user_get_user_name (user)), user);
                         g_debug ("loaded user: %s", user_get_user_name (user));
@@ -843,15 +892,24 @@ throw_error (GDBusMethodInvocation *cont
 }
 
 static User *
+#ifdef HAVE_SHADOW_H
 add_new_user_for_pwent (Daemon        *daemon,
                         struct passwd *pwent,
                         struct spwd   *spent)
+#else
+add_new_user_for_pwent (Daemon        *daemon,
+                        struct passwd *pwent)
+#endif
 {
         DaemonPrivate *priv = daemon_get_instance_private (daemon);
         User *user;
 
         user = user_new (daemon, pwent->pw_uid);
+#ifdef HAVE_SHADOW_H
         user_update_from_pwent (user, pwent, spent);
+#else
+        user_update_from_pwent (user, pwent);
+#endif
         user_register (user);
 
         g_hash_table_insert (priv->users,
@@ -880,9 +938,13 @@ daemon_local_find_user_by_id (Daemon *da
         user = g_hash_table_lookup (priv->users, pwent->pw_name);
 
         if (user == NULL) {
+#ifdef HAVE_SHADOW_H
                 struct spwd *spent;
                 spent = getspnam (pwent->pw_name);
                 user = add_new_user_for_pwent (daemon, pwent, spent);
+#else
+                user = add_new_user_for_pwent (daemon, pwent);
+#endif
 
                 priv->explicitly_requested_users = g_list_append (priv->explicitly_requested_users,
                                                                   g_strdup (pwent->pw_name));
@@ -908,9 +970,13 @@ daemon_local_find_user_by_name (Daemon
         user = g_hash_table_lookup (priv->users, pwent->pw_name);
 
         if (user == NULL) {
+#ifdef HAVE_SHADOW_H
                 struct spwd *spent;
                 spent = getspnam (pwent->pw_name);
                 user = add_new_user_for_pwent (daemon, pwent, spent);
+#else
+                user = add_new_user_for_pwent (daemon, pwent);
+#endif
 
                 priv->explicitly_requested_users = g_list_append (priv->explicitly_requested_users,
                                                                   g_strdup (pwent->pw_name));
@@ -1106,10 +1172,12 @@ daemon_create_user_authorized_cb (Daemon
 
         sys_log (context, "create user '%s'", cd->user_name);
 
-        argv[0] = "/usr/sbin/useradd";
-        argv[1] = "-m";
-        argv[2] = "-c";
-        argv[3] = cd->real_name;
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "useradd";
+        argv[2] = cd->user_name;
+        argv[3] = "-m";
+        argv[4] = "-c";
+        argv[5] = cd->real_name;
         if (cd->account_type == ACCOUNT_TYPE_ADMINISTRATOR) {
                 if (EXTRA_ADMIN_GROUPS != NULL && EXTRA_ADMIN_GROUPS[0] != '\0')
                         admin_groups = g_strconcat (ADMIN_GROUP, ",",
@@ -1117,15 +1185,11 @@ daemon_create_user_authorized_cb (Daemon
                 else
                         admin_groups = g_strdup (ADMIN_GROUP);
 
-                argv[4] = "-G";
-                argv[5] = admin_groups;
-                argv[6] = "--";
-                argv[7] = cd->user_name;
+                argv[6] = "-G";
+                argv[7] = admin_groups;
                 argv[8] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
                 argv[6] = NULL;
         }
         else {
@@ -1292,7 +1356,7 @@ daemon_delete_user_authorized_cb (Daemon
         DeleteUserData *ud = data;
         g_autoptr(GError) error = NULL;
         struct passwd *pwent;
-        const gchar *argv[6];
+        const gchar *argv[5];
         User *user;
 
         pwent = getpwuid (ud->uid);
@@ -1318,19 +1382,16 @@ daemon_delete_user_authorized_cb (Daemon
 
         user_set_saved (user, FALSE);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "userdel";
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
+                argv[2] = pwent->pw_name;
+                argv[3] = "-r";
+                argv[4] = NULL;
         }
         else {
-                argv[1] = "-f";
-                argv[2] = "--";
-                argv[3] = pwent->pw_name;
-                argv[4] = NULL;
+                argv[2] = pwent->pw_name;
+                argv[3] = NULL;
         }
 
         if (!spawn_with_login_uid (context, argv, &error)) {
