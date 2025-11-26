--- lib/erl_interface/src/connect/ei_resolve.c.orig	2025-10-20 12:50:59 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -433,7 +433,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 }
 
