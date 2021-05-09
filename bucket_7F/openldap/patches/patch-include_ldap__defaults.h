--- include/ldap_defaults.h.orig	2021-04-29 17:42:58 UTC
+++ include/ldap_defaults.h
@@ -39,7 +39,7 @@
 #define LDAP_ENV_PREFIX "LDAP"
 
 /* default ldapi:// socket */
-#define LDAPI_SOCK LDAP_RUNDIR LDAP_DIRSEP "run" LDAP_DIRSEP "ldapi"
+#define LDAPI_SOCK "/var/run" LDAP_DIRSEP "openldap" LDAP_DIRSEP "ldapi"
 
 /*
  * SLAPD DEFINITIONS
