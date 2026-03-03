--- lib/krb5/os/addr.c.orig	2026-01-29 23:18:10 UTC
+++ lib/krb5/os/addr.c
@@ -62,10 +62,10 @@ k5_sockaddr_to_address(const struct sock
         }
 #ifndef _WIN32
     } else if (sa->sa_family == AF_UNIX && local_use) {
-        const struct sockaddr_un *sun = sa2sun(sa);
+        const struct sockaddr_un *xsun = sa2sun(sa);
         out->addrtype = ADDRTYPE_UNIXSOCK;
-        out->length = strlen(sun->sun_path);
-        out->contents = (uint8_t *)sun->sun_path;
+        out->length = strlen(xsun->sun_path);
+        out->contents = (uint8_t *)xsun->sun_path;
 #endif
     } else {
         return KRB5_PROG_ATYPE_NOSUPP;
