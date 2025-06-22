--- lib/erl_interface/src/connect/ei_resolve.c.orig	2025-06-13 14:54:33 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -433,7 +433,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 }
 
