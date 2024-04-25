--- src/http/ngx_http_upstream_round_robin.c.orig	2024-04-23 14:04:32 UTC
+++ src/http/ngx_http_upstream_round_robin.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 #define ngx_http_upstream_tries(p) ((p)->tries                                \
                                     + ((p)->next ? (p)->next->tries : 0))
@@ -103,7 +106,14 @@ ngx_http_upstream_init_round_robin(ngx_c
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
-
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 *peerp = &peer[n];
                 peerp = &peer[n].next;
                 n++;
@@ -173,7 +183,15 @@ ngx_http_upstream_init_round_robin(ngx_c
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
-
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                }
+                else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 *peerp = &peer[n];
                 peerp = &peer[n].next;
                 n++;
@@ -241,6 +259,9 @@ ngx_http_upstream_init_round_robin(ngx_c
         peer[i].max_conns = 0;
         peer[i].max_fails = 1;
         peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         *peerp = &peer[i];
         peerp = &peer[i].next;
     }
@@ -358,6 +379,9 @@ ngx_http_upstream_create_round_robin_pee
         peer[0].max_conns = 0;
         peer[0].max_fails = 1;
         peer[0].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[0].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         peers->peer = peer;
 
     } else {
@@ -392,6 +416,9 @@ ngx_http_upstream_create_round_robin_pee
             peer[i].max_conns = 0;
             peer[i].max_fails = 1;
             peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
             *peerp = &peer[i];
             peerp = &peer[i].next;
         }
@@ -457,6 +484,12 @@ ngx_http_upstream_get_round_robin_peer(n
             goto failed;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto failed;
+        }
+#endif
+
         rrp->current = peer;
 
     } else {
@@ -551,6 +584,12 @@ ngx_http_upstream_get_peer(ngx_http_upst
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
