--- src/unix/udp.c.orig	2019-09-09 16:53:10 UTC
+++ src/unix/udp.c
@@ -664,6 +664,9 @@ static int uv__udp_set_source_membership
                                           const char* interface_addr,
                                           const struct sockaddr_in* source_addr,
                                           uv_membership membership) {
+#ifdef __DragonFly__
+    return UV_EINVAL;
+#else
   struct ip_mreq_source mreq;
   int optname;
   int err;
@@ -701,6 +704,7 @@ static int uv__udp_set_source_membership
   }
 
   return 0;
+#endif
 }
 
 
@@ -709,6 +713,9 @@ static int uv__udp_set_source_membership
                                           const char* interface_addr,
                                           const struct sockaddr_in6* source_addr,
                                           uv_membership membership) {
+#ifdef __DragonFly__
+    return UV_EINVAL;
+#else
   struct group_source_req mreq;
   struct sockaddr_in6 addr6;
   int optname;
@@ -748,6 +755,7 @@ static int uv__udp_set_source_membership
   }
 
   return 0;
+#endif
 }
 
 
