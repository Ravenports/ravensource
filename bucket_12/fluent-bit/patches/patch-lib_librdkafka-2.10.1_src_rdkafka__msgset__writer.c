--- lib/librdkafka-2.15.0/src/rdkafka_msgset_writer.c.orig	2026-08-15 03:52:07 UTC
+++ lib/librdkafka-2.15.0/src/rdkafka_msgset_writer.c
@@ -1043,7 +1043,7 @@ static int rd_kafka_msgset_writer_compre
         int comp_level =
             msetw->msetw_rktp->rktp_rkt->rkt_conf.compression_level;
         err = rd_kafka_gzip_compress(msetw->msetw_rkb, comp_level, slice,
-                                     &ciov->iov_base, &ciov->iov_len);
+                                     (void **)&ciov->iov_base, &ciov->iov_len);
         return (err ? -1 : 0);
 }
 #endif
@@ -1108,7 +1108,7 @@ rd_kafka_msgset_writer_compress_snappy(r
                                        struct iovec *ciov) {
         rd_kafka_resp_err_t err;
         err = rd_kafka_snappy_compress_slice(msetw->msetw_rkb, slice,
-                                             &ciov->iov_base, &ciov->iov_len);
+                                             (void **)&ciov->iov_base, &ciov->iov_len);
         return (err ? -1 : 0);
 }
 #endif
@@ -1125,7 +1125,7 @@ static int rd_kafka_msgset_writer_compre
         err = rd_kafka_lz4_compress(msetw->msetw_rkb,
                                     /* Correct or incorrect HC */
                                     msetw->msetw_MsgVersion >= 1 ? 1 : 0,
-                                    comp_level, slice, &ciov->iov_base,
+                                    comp_level, slice, (void **)&ciov->iov_base,
                                     &ciov->iov_len);
         return (err ? -1 : 0);
 }
@@ -1141,7 +1141,7 @@ static int rd_kafka_msgset_writer_compre
         int comp_level =
             msetw->msetw_rktp->rktp_rkt->rkt_conf.compression_level;
         err = rd_kafka_zstd_compress(msetw->msetw_rkb, comp_level, slice,
-                                     &ciov->iov_base, &ciov->iov_len);
+                                     (void **)&ciov->iov_base, &ciov->iov_len);
         return (err ? -1 : 0);
 }
 #endif
