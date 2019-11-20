--- lib/softoken/pkcs11.c.orig	2019-11-19 19:55:30 UTC
+++ lib/softoken/pkcs11.c
@@ -3209,8 +3209,8 @@ nsc_CommonInitialize(CK_VOID_PTR pReserv
         char buf[200];
         int major = 0, minor = 0;
 
-        long rv = sysinfo(SI_RELEASE, buf, sizeof(buf));
-        if (rv > 0 && rv < sizeof(buf)) {
+        long sunrv = sysinfo(SI_RELEASE, buf, sizeof(buf));
+        if (sunrv > 0 && sunrv < sizeof(buf)) {
             if (2 == sscanf(buf, "%d.%d", &major, &minor)) {
                 /* Are we on Solaris 10 or greater ? */
                 if (major > 5 || (5 == major && minor >= 10)) {
