--- src/vde_router/vder_icmp.c.orig	2022-05-02 17:39:19 UTC
+++ src/vde_router/vder_icmp.c
@@ -61,7 +61,11 @@ int vder_icmp_ttl_expired(uint32_t dst,
 
 int vder_icmp_filter(uint32_t dst, uint8_t *foot)
 {
+#if defined(__NetBSD__)
+	return 0;
+#else
 	return vder_icmp_send(dst, ICMP_UNREACH, ICMP_UNREACH_FILTER_PROHIB, foot);
+#endif
 }
 
 /* Parse an incoming icmp packet
