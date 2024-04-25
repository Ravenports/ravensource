--- src/http/modules/ngx_http_upstream_ip_hash_module.c.orig	2024-04-23 14:04:32 UTC
+++ src/http/modules/ngx_http_upstream_ip_hash_module.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 typedef struct {
     /* the round robin data must be first */
@@ -208,6 +211,15 @@ ngx_http_upstream_get_ip_hash_peer(ngx_p
             goto next;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+            "get ip_hash peer, check_index: %ui",
+             peer->check_index);
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto next;
+        }
+#endif
+
         if (peer->max_fails
             && peer->fails >= peer->max_fails
             && now - peer->checked <= peer->fail_timeout)
