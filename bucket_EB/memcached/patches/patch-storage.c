--- storage.c.orig	2025-12-17 00:16:18 UTC
+++ storage.c
@@ -310,7 +310,11 @@ int storage_get_item(LIBEVENT_THREAD *t,
         }
 
         // fill the header so we can get the full data + crc back.
+#if defined(__sun__)
+        eio->iov[0].iov_base = (caddr_t)new_it;
+#else
         eio->iov[0].iov_base = new_it;
+#endif
         eio->iov[0].iov_len = ITEM_ntotal(new_it) - new_it->nbytes;
         ciovcnt++;
 
