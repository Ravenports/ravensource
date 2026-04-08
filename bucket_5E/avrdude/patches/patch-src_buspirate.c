--- src/buspirate.c.orig	2025-06-23 09:03:44 UTC
+++ src/buspirate.c
@@ -139,7 +139,7 @@ static int buspirate_recv_bin(const PROG
 
 static int buspirate_expect_bin(const PROGRAMMER *pgm,
   unsigned char *send_data, size_t send_len, unsigned char *expect_data, size_t expect_len) {
-  unsigned char *recv_buf = alloca(expect_len);
+  unsigned char *recv_buf = __builtin_alloca(expect_len);
 
   if((my.flag & BP_FLAG_IN_BINMODE) == 0) {
     pmsg_error("called from ascii mode\n");
