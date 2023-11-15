Use correct prototype for getprotobynumber_r() on SunOS

--- fdname.c.orig	2023-11-13 19:31:08 UTC
+++ fdname.c
@@ -250,7 +250,7 @@ int sockname(int fd, FILE *outfile, char
    /*Linux struct ifreq ifc = {{{ 0 }}};*/
    struct ifreq ifc = {{ 0 }};
 #endif
-   int rc;
+   int rc = 0;
 
 #if defined(SO_PROTOCOL) || defined(SO_PROTOTYPE)
    optlen = sizeof(proto);
@@ -280,7 +280,12 @@ int sockname(int fd, FILE *outfile, char
 
 #if defined(SO_PROTOCOL) || defined(SO_PROTOTYPE)
 #if HAVE_GETPROTOBYNUMBER_R==1 /* Linux */
+# if defined(__sun)
+   protoentp = getprotobynumber_r(proto, &protoent, protoname, sizeof(protoname));
+   rc = errno;
+# else
    rc = getprotobynumber_r(proto, &protoent, protoname, sizeof(protoname), &protoentp);
+# endif
    if (protoentp == NULL) {
       Warn2("sockname(): getprotobynumber_r(proto=%d, ...): %s",
 	    proto, strerror(rc));
