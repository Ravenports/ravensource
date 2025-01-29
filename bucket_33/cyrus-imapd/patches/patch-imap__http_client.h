--- imap/http_client.h.orig	2025-01-21 23:32:31 UTC
+++ imap/http_client.h
@@ -58,7 +58,7 @@ struct body_t {
     unsigned char framing;              /* Message framing   */
     unsigned char te;                   /* Transfer-Encoding */
     unsigned max;                       /* Max allowed len   */
-    ulong len;                          /* Content-Length    */
+    unsigned long len;                  /* Content-Length    */
     struct buf payload;                 /* Payload           */
 };
 
