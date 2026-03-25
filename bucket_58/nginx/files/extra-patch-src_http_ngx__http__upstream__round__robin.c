--- src/http/ngx_http_upstream_round_robin.c.orig	2026-03-10 15:29:07 UTC
+++ src/http/ngx_http_upstream_round_robin.c
@@ -10,6 +10,9 @@
 #include <ngx_http.h>
 #include <ngx_md5.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 #define ngx_http_upstream_tries(p) ((p)->tries                                \
                                     + ((p)->next ? (p)->next->tries : 0))
@@ -442,6 +445,9 @@ ngx_http_upstream_init_round_robin(ngx_c
         peer[i].max_conns = 0;
         peer[i].max_fails = 1;
         peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         *peerp = &peer[i];
         peerp = &peer[i].next;
     }
@@ -624,6 +630,9 @@ ngx_http_upstream_create_round_robin_pee
         peer[0].max_conns = 0;
         peer[0].max_fails = 1;
         peer[0].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[0].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         peers->peer = peer;
 
     } else {
@@ -658,6 +667,9 @@ ngx_http_upstream_create_round_robin_pee
             peer[i].max_conns = 0;
             peer[i].max_fails = 1;
             peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
             *peerp = &peer[i];
             peerp = &peer[i].next;
         }
@@ -737,6 +749,12 @@ ngx_http_upstream_get_round_robin_peer(n
         }
 #endif
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto failed;
+        }
+#endif
+
         rrp->current = peer;
         ngx_http_upstream_rr_peer_ref(peers, peer);
 
@@ -870,6 +888,12 @@ ngx_http_upstream_get_peer(ngx_http_upst
             continue;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            continue;
+        }
+#endif
+
         if (peer->max_fails
             && peer->fails >= peer->max_fails
             && now - peer->checked <= peer->fail_timeout)
