--- tests/bitwise.c.orig	2025-02-20 18:48:21 UTC
+++ tests/bitwise.c
@@ -22,7 +22,7 @@ static void test_bitwise_size(size_t bit
 {
   kate_pack_buffer kpb;
   size_t data_size=bits*4; /* good margin */
-  unsigned char *data=alloca(data_size);
+  unsigned char *data=__builtin_alloca(data_size);
   size_t n,d;
   kate_uint32_t rnd;
   int read;
