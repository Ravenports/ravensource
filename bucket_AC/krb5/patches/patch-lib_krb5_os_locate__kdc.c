--- lib/krb5/os/locate_kdc.c.orig	2026-11-06 23:01:49 UTC
+++ lib/krb5/os/locate_kdc.c
@@ -296,16 +296,16 @@ locate_srv_conf_1(krb5_context context,
 
 #ifndef _WIN32
         if (hostspec[0] == '/') {
-            struct sockaddr_un sun = { 0 };
+            struct sockaddr_un xsun = { 0 };
 
-            sun.sun_family = AF_UNIX;
-            if (strlcpy(sun.sun_path, hostspec, sizeof(sun.sun_path)) >=
-                sizeof(sun.sun_path)) {
+            xsun.sun_family = AF_UNIX;
+            if (strlcpy(xsun.sun_path, hostspec, sizeof(xsun.sun_path)) >=
+                sizeof(xsun.sun_path)) {
                 code = ENAMETOOLONG;
                 goto cleanup;
             }
-            code = add_addr_to_list(serverlist, UNIXSOCK, AF_UNIX, sizeof(sun),
-                                    (struct sockaddr *)&sun);
+            code = add_addr_to_list(serverlist, UNIXSOCK, AF_UNIX, sizeof(xsun),
+                                    (struct sockaddr *)&xsun);
             if (code)
                 goto cleanup;
             continue;
