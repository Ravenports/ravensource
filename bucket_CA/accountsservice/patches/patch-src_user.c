--- src/user.c.orig	2023-08-12 19:01:30 UTC
+++ src/user.c
@@ -507,7 +507,11 @@ user_update_from_pwent (User          *u
                 user->account_expiration_policy_known = TRUE;
         }
         else
+#if defined(__sun)
+                user->user_expiration_time = NULL;
+#else
                 user->user_expiration_time = g_date_time_new_from_unix_utc(pwent->pw_expire);
+#endif
 
         accounts_user_set_password_mode (ACCOUNTS_USER (user), mode);
         is_system_account = !user_classify_is_human (accounts_user_get_uid (ACCOUNTS_USER (user)),
