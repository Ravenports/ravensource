--- router/src/harness/include/mysql/harness/net_ts/internet.h.orig	2025-07-09 08:56:06 UTC
+++ router/src/harness/include/mysql/harness/net_ts/internet.h
@@ -45,6 +45,7 @@
 #include <arpa/inet.h>    // inet_ntop
 #include <netdb.h>        // getaddrinfo
 #include <netinet/in.h>   // in_addr_t
+#include <sys/types.h>    // u_int32_t
 #include <netinet/ip6.h>  // in6_addr_t
 #include <netinet/tcp.h>  // TCP_NODELAY
 #include <sys/ioctl.h>    // ioctl
@@ -599,8 +600,12 @@ class resolver_base {
   static constexpr flags canonical_name = AI_CANONNAME;
   static constexpr flags numeric_host = AI_NUMERICHOST;
   static constexpr flags numeric_service = AI_NUMERICSERV;
+#ifdef AI_V4MAPPED
   static constexpr flags v4_mapped = AI_V4MAPPED;
+#endif
+#ifdef AI_ALL
   static constexpr flags all_matching = AI_ALL;
+#endif
   static constexpr flags address_configured = AI_ADDRCONFIG;
 };
 
