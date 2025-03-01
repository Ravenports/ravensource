From 0858742abe523d368bf08e4fe2f875b2c764cabf Mon Sep 17 00:00:00 2001
From: Eduardo Silva <eduardo@chronosphere.io>
Date: Thu, 27 Feb 2025 11:05:21 -0600
Subject: [PATCH] out_http: fix logic to handle status of compressed payloads
 (fix #10016)

Signed-off-by: Eduardo Silva <eduardo@chronosphere.io>
---
 plugins/out_http/http.c | 18 +++++++++++++-----
 1 file changed, 13 insertions(+), 5 deletions(-)

--- plugins/out_http/http.c.orig
+++ plugins/out_http/http.c
@@ -114,7 +114,7 @@ static int http_post(struct flb_out_http *ctx,
                      const char *tag, int tag_len,
                      char **headers)
 {
-    int ret;
+    int ret = 0;
     int out_ret = FLB_OK;
     int compressed = FLB_FALSE;
     size_t b_sent;
@@ -143,26 +143,34 @@ static int http_post(struct flb_out_http *ctx,
     payload_size = body_len;
 
     /* Should we compress the payload ? */
+    ret = 0;
     if (ctx->compress_gzip == FLB_TRUE) {
         ret = flb_gzip_compress((void *) body, body_len,
                                 &payload_buf, &payload_size);
+        if (ret == 0) {
+            compressed = FLB_TRUE;
+        }
     }
     else if (ctx->compress_snappy == FLB_TRUE) {
         ret = flb_snappy_compress((void *) body, body_len,
-                                  &payload_buf, &payload_size);
+                                  (char **) &payload_buf, &payload_size);
+        if (ret == 0) {
+            compressed = FLB_TRUE;
+        }
     }
     else if (ctx->compress_zstd == FLB_TRUE) {
         ret = flb_zstd_compress((void *) body, body_len,
                                 &payload_buf, &payload_size);
+        if (ret == 0) {
+            compressed = FLB_TRUE;
+        }
     }
 
     if (ret == -1) {
         flb_plg_warn(ctx->ins, "could not compress payload, sending as it is");
         compressed = FLB_FALSE;
     }
-    else {
-        compressed = FLB_TRUE;
-    }
+
 
     /* Create HTTP client context */
     c = flb_http_client(u_conn, FLB_HTTP_POST, ctx->uri,
