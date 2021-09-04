--- lib/softoken/pkcs11.c.orig	2021-08-26 19:01:21 UTC
+++ lib/softoken/pkcs11.c
@@ -3369,8 +3369,8 @@ nsc_CommonInitialize(CK_VOID_PTR pReserv
         char buf[200];
         int major = 0, minor = 0;
 
-        long rv = sysinfo(SI_RELEASE, buf, sizeof(buf));
-        if (rv > 0 && rv < sizeof(buf)) {
+        long sunrv = sysinfo(SI_RELEASE, buf, sizeof(buf));
+        if (sunrv > 0 && sunrv < sizeof(buf)) {
             if (2 == sscanf(buf, "%d.%d", &major, &minor)) {
                 /* Are we on Solaris 10 or greater ? */
                 if (major > 5 || (5 == major && minor >= 10)) {
