--- src/stk500.c.orig	2025-06-23 09:03:44 UTC
+++ src/stk500.c
@@ -992,7 +992,7 @@ static int set_memchr_a_div(const PROGRA
 
 static int stk500_paged_write(const PROGRAMMER *pgm, const AVRPART *p, const AVRMEM *m,
   unsigned int page_size, unsigned int addr, unsigned int n_bytes) {
-  unsigned char *buf = alloca(page_size + 16);
+  unsigned char *buf = __builtin_alloca(page_size + 16);
   int memchr;
   int a_div;
   int block_size;
