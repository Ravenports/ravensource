--- lib/erl_interface/src/connect/ei_resolve.c.orig	2019-01-15 18:35:10 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -653,7 +653,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 #endif
 #endif
