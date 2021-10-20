--- compile.c.orig	2020-03-31 11:23:13 UTC
+++ compile.c
@@ -8465,7 +8465,7 @@ struct ibf_dump {
 rb_iseq_t * iseq_alloc(void);
 
 struct ibf_load {
-    const RUBY_ALIGNAS(SIZEOF_VALUE) char *buff;
+    const char *buff;
     const struct ibf_header *header;
     ID *id_list;     /* [id0, ...] */
     VALUE iseq_list; /* [iseq0, ...] */
