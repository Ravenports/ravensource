--- lib/erl_interface/src/connect/ei_resolve.c.orig	2020-07-20 11:42:52 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -438,7 +438,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 #endif
 #endif
