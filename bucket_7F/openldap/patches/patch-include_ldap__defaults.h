--- include/ldap_defaults.h.orig	2024-05-21 17:19:11 UTC
+++ include/ldap_defaults.h
@@ -40,7 +40,7 @@
 
 /* default ldapi:// socket */
 #ifndef LDAPI_SOCK
-#define LDAPI_SOCK LDAP_RUNDIR LDAP_DIRSEP "run" LDAP_DIRSEP "ldapi"
+#define LDAPI_SOCK "/var/run" LDAP_DIRSEP "openldap" LDAP_DIRSEP "ldapi"
 #endif
 
 /*
