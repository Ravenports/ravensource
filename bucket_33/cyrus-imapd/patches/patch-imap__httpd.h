--- imap/httpd.h.orig	2023-05-21 23:30:54 UTC
+++ imap/httpd.h
@@ -289,7 +289,7 @@ typedef int (*encode_proc_t)(struct tran
 
 /* Meta-data for response body (payload & representation headers) */
 struct resp_body_t {
-    ulong len;                          /* Content-Length   */
+    unsigned long len;                  /* Content-Length   */
     struct range *range;                /* Content-Range    */
     struct {
         const char *fname;
