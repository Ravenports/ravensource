--- src/unix/udp.c.orig	2020-05-17 15:34:37 UTC
+++ src/unix/udp.c
@@ -854,7 +854,7 @@ static int uv__udp_set_membership6(uv_ud
 }
 
 
-#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__) && !defined(__DragonFly__)
 static int uv__udp_set_source_membership4(uv_udp_t* handle,
                                           const struct sockaddr_in* multicast_addr,
                                           const char* interface_addr,
@@ -1031,7 +1031,7 @@ int uv_udp_set_source_membership(uv_udp_
                                  const char* interface_addr,
                                  const char* source_addr,
                                  uv_membership membership) {
-#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__) && !defined(__DragonFly__)
   int err;
   union uv__sockaddr mcast_addr;
   union uv__sockaddr src_addr;
