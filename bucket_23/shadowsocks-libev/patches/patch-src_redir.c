--- src/redir.c.orig	2025-01-20 03:11:47 UTC
+++ src/redir.c
@@ -37,9 +37,15 @@
 #include <unistd.h>
 #include <getopt.h>
 #include <limits.h>
+#if defined(__linux__)
 #include <linux/if.h>
 #include <linux/netfilter_ipv4.h>
 #include <linux/netfilter_ipv6/ip6_tables.h>
+#else
+#define SOL_IP          IPPROTO_IP
+#define SOL_IPV6        IPPROTO_IPV6
+#define SO_ORIGINAL_DST 0
+#endif
 
 #include <libcork/core.h>
 
