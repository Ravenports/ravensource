--- lib/monkey/mk_core/mk_iov.c.orig	2022-03-22 22:42:32 UTC
+++ lib/monkey/mk_core/mk_iov.c
@@ -57,7 +57,7 @@ struct mk_iov *mk_iov_create(int n, int
 
     /* Set pointer address */
     iov     = p;
-    iov->io = (struct mk_iov *)((uint8_t *)p + sizeof(struct mk_iov));
+    iov->io = (struct iovec *)((uint8_t *)p + sizeof(struct mk_iov));
     iov->buf_to_free = (void *) ((uint8_t*)p + sizeof(struct mk_iov) + s_iovec);
 
     mk_iov_init(iov, n, offset);
