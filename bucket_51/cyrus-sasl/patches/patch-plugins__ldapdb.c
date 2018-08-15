Index: plugins/ldapdb.c
diff -u -p plugins/ldapdb.c.orig plugins/ldapdb.c
--- plugins/ldapdb.c.orig	2012-01-27 23:31:36 UTC
+++ plugins/ldapdb.c
@@ -251,6 +251,8 @@ static int ldapdb_auxprop_lookup(void *g
 
 #if defined(LDAP_PROXY_AUTHZ_FAILURE)
 	case LDAP_PROXY_AUTHZ_FAILURE:
+#else
+	case LDAP_X_PROXY_AUTHZ_FAILURE:
 #endif
 	case LDAP_INAPPROPRIATE_AUTH:
 	case LDAP_INVALID_CREDENTIALS:
