--- src/http/ngx_http_upstream_round_robin.h.orig	2024-04-23 14:04:32 UTC
+++ src/http/ngx_http_upstream_round_robin.h
@@ -49,6 +49,10 @@ struct ngx_http_upstream_rr_peer_s {
     ngx_atomic_t                    lock;
 #endif
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                      check_index;
+#endif
+
     ngx_http_upstream_rr_peer_t    *next;
 
     NGX_COMPAT_BEGIN(32)
