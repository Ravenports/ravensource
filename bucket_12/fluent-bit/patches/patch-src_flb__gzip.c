--- src/flb_gzip.c.orig	2025-09-24 14:28:05 UTC
+++ src/flb_gzip.c
@@ -108,7 +108,7 @@ static inline void flb_hex_dump(uint8_t
         line_length = 40;
     }
 
-    printable_line = alloca(line_length + 1);
+    printable_line = __builtin_alloca(line_length + 1);
 
     if (NULL == printable_line)
     {
