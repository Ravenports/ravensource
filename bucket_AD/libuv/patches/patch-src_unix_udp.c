--- src/unix/udp.c.orig	2020-03-12 15:18:05.269264000 +0100
+++ src/unix/udp.c	2020-03-12 15:18:29.952654000 +0100
@@ -851,7 +851,7 @@
 }
 
 
-#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__) && !defined(__DragonFly__)
 static int uv__udp_set_source_membership4(uv_udp_t* handle,
                                           const struct sockaddr_in* multicast_addr,
                                           const char* interface_addr,
@@ -1040,7 +1040,7 @@
                                  const char* interface_addr,
                                  const char* source_addr,
                                  uv_membership membership) {
-#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__ANDROID__) && !defined(__DragonFly__)
   int err;
   struct sockaddr_storage mcast_addr;
   struct sockaddr_in* mcast_addr4;
