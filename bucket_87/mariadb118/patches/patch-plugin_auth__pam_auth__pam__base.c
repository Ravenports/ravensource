--- plugin/auth_pam/auth_pam_base.c.orig	2026-01-31 13:27:48 UTC
+++ plugin/auth_pam/auth_pam_base.c
@@ -128,11 +128,7 @@ static int conv(int n, const struct pam_
 
 #define DO(X) if ((status = (X)) != PAM_SUCCESS) goto end
 
-#if defined(SOLARIS) || defined(__sun)
-typedef void** pam_get_item_3_arg;
-#else
 typedef const void** pam_get_item_3_arg;
-#endif
 
 static int pam_auth_base(struct param *param, MYSQL_SERVER_AUTH_INFO *info)
 {
