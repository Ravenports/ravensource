--- ipmipower/ipmipower_connection.c.orig	2026-03-11 18:07:37 UTC
+++ ipmipower/ipmipower_connection.c
@@ -297,8 +297,12 @@ _connection_setup (struct ipmipower_conn
 
   if ((ret = getaddrinfo (ic->hostname, port_str, &ai_hints, &ai_res)))
     {
+#if defined __Linux__
       if (ret == EAI_NODATA
 	  || ret == EAI_NONAME)
+#else
+      if (ret == EAI_NONAME)
+#endif
         ipmipower_output (IPMIPOWER_MSG_TYPE_HOSTNAME_INVALID, ic->hostname, NULL);
       else
         {
