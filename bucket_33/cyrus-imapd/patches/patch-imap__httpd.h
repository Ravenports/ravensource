--- imap/httpd.h.orig	2021-04-19 03:14:38 UTC
+++ imap/httpd.h
@@ -285,7 +285,7 @@ typedef int (*encode_proc_t)(struct tran
 
 /* Meta-data for response body (payload & representation headers) */
 struct resp_body_t {
-    ulong len;                          /* Content-Length   */
+    unsigned long len;                  /* Content-Length   */
     struct range *range;                /* Content-Range    */
     struct {
         const char *fname;
