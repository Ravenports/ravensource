--- compile.c.orig	2021-11-24 11:53:13 UTC
+++ compile.c
@@ -8490,7 +8490,7 @@ struct ibf_dump {
 rb_iseq_t * iseq_alloc(void);
 
 struct ibf_load {
-    const RUBY_ALIGNAS(SIZEOF_VALUE) char *buff;
+    const char *buff;
     const struct ibf_header *header;
     ID *id_list;     /* [id0, ...] */
     VALUE iseq_list; /* [iseq0, ...] */
