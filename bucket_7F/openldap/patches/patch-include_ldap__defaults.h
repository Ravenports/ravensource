--- include/ldap_defaults.h.orig	2022-05-06 21:40:32.972273000 +0200
+++ include/ldap_defaults.h	2022-05-06 21:41:20.793768000 +0200
@@ -40,7 +40,7 @@
 
 /* default ldapi:// socket */
 #ifndef LDAPI_SOCK
-#define LDAPI_SOCK LDAP_RUNDIR LDAP_DIRSEP "run" LDAP_DIRSEP "ldapi"
+#define LDAPI_SOCK "/var/run" LDAP_DIRSEP "openldap" LDAP_DIRSEP "ldapi"
 #endif
 
 /*
