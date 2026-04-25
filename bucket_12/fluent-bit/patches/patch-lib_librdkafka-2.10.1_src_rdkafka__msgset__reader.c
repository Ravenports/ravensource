--- lib/librdkafka-2.10.1/src/rdkafka_msgset_reader.c.orig	2026-04-14 17:27:00 UTC
+++ lib/librdkafka-2.10.1/src/rdkafka_msgset_reader.c
@@ -408,7 +408,7 @@ rd_kafka_msgset_reader_decompress(rd_kaf
                                             /* @warning Will modify compressed
                                              *          if no proper HC */
                                             (char *)compressed, compressed_size,
-                                            &iov.iov_base, &iov.iov_len);
+                                            (void **)&iov.iov_base, &iov.iov_len);
                 if (err)
                         goto err;
         } break;
