--- lib/erl_interface/src/connect/ei_resolve.c.orig	2026-04-23 10:09:44 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -432,6 +432,9 @@ struct hostent *ei_gethostbyname_r(const
       *h_errnop = err;
 
   return result;
+#elif defined __NetBSD__
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #else
   return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
 #endif
