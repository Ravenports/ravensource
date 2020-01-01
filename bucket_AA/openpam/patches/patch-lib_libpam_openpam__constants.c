--- lib/libpam/openpam_constants.c.orig	2019-02-24 20:15:19 UTC
+++ lib/libpam/openpam_constants.c
@@ -169,17 +169,13 @@ const char *pam_sm_func_name[PAM_NUM_PRI
 const char *openpam_policy_path[] = {
 	"/etc/pam.d/",
 	"/etc/pam.conf",
-	"/usr/local/etc/pam.d/",
-	"/usr/local/etc/pam.conf",
+	"@PREFIX@/etc/pam.d/",
+	"@PREFIX@/etc/pam.conf",
 	NULL
 };
 
 const char *openpam_module_path[] = {
-#ifdef OPENPAM_MODULES_DIRECTORY
-	OPENPAM_MODULES_DIRECTORY,
-#else
-	"/usr/lib",
-	"/usr/local/lib",
-#endif
+	"@PREFIX@/lib/openpam",
+	@SYSTEM_MODULES@
 	NULL
 };
