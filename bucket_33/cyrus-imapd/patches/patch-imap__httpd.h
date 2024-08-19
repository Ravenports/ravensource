--- imap/httpd.h.orig	2024-08-16 00:27:41 UTC
+++ imap/httpd.h
@@ -286,7 +286,7 @@ typedef int (*encode_proc_t)(struct tran
 
 /* Meta-data for response body (payload & representation headers) */
 struct resp_body_t {
-    ulong len;                          /* Content-Length   */
+    unsigned long len;                  /* Content-Length   */
     struct range *range;                /* Content-Range    */
     struct {
         const char *fname;
