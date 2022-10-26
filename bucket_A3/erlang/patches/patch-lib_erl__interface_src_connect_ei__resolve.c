--- lib/erl_interface/src/connect/ei_resolve.c.orig	2022-10-24 08:12:46 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -431,7 +431,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 }
 
