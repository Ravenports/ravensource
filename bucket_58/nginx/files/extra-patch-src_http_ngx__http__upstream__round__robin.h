--- src/http/ngx_http_upstream_round_robin.h.orig	2026-03-10 15:29:07 UTC
+++ src/http/ngx_http_upstream_round_robin.h
@@ -89,6 +89,10 @@ struct ngx_http_upstream_rr_peer_s {
     ngx_str_t                       sid;
 #endif
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                      check_index;
+#endif
+
     ngx_http_upstream_rr_peer_t    *next;
 
     NGX_COMPAT_BEGIN(13)
