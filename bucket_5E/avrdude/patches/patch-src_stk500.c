--- src/stk500.c.orig	2026-07-11 11:11:28 UTC
+++ src/stk500.c
@@ -1001,7 +1001,7 @@ static int set_memchr_a_div(const PROGRA
 
 static int stk500_paged_write(const PROGRAMMER *pgm, const AVRPART *p, const AVRMEM *m,
   unsigned int page_size, unsigned int addr, unsigned int n_bytes) {
-  unsigned char *buf = alloca(page_size + 16);
+  unsigned char *buf = __builtin_alloca(page_size + 16);
   int memchr;
   int a_div;
   int block_size;
