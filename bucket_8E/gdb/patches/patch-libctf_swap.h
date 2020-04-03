--- libctf/swap.h.orig	2020-02-08 12:50:14 UTC
+++ libctf/swap.h
@@ -43,7 +43,7 @@ bswap_32 (uint32_t v)
 	  | ((v & 0x000000ff) << 24));
 }
 
-inline uint64_t
+static inline uint64_t
 bswap_identity_64 (uint64_t v)
 {
   return v;
