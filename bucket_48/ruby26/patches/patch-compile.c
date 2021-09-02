--- compile.c.orig	2021-09-02 03:09:01 UTC
+++ compile.c
@@ -8466,7 +8466,7 @@ struct ibf_dump {
 rb_iseq_t * iseq_alloc(void);
 
 struct ibf_load {
-    const RUBY_ALIGNAS(SIZEOF_VALUE) char *buff;
+    const char *buff;
     const struct ibf_header *header;
     ID *id_list;     /* [id0, ...] */
     VALUE iseq_list; /* [iseq0, ...] */
