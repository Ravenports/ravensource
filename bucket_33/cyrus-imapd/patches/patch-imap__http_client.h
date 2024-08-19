--- imap/http_client.h.orig	2024-07-24 00:40:43 UTC
+++ imap/http_client.h
@@ -58,7 +58,7 @@ struct body_t {
     unsigned char framing;              /* Message framing   */
     unsigned char te;                   /* Transfer-Encoding */
     unsigned max;                       /* Max allowed len   */
-    ulong len;                          /* Content-Length    */
+    unsigned long len;                  /* Content-Length    */
     struct buf payload;                 /* Payload           */
 };
 
