--- src/flb_gzip.c.orig	2025-02-25 13:27:54 UTC
+++ src/flb_gzip.c
@@ -98,7 +98,7 @@ static inline void flb_hex_dump(uint8_t
         line_length = 40;
     }
 
-    printable_line = alloca(line_length + 1);
+    printable_line = __builtin_alloca(line_length + 1);
 
     if (NULL == printable_line)
     {
