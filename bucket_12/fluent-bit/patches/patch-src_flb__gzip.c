--- src/flb_gzip.c.orig	2025-05-13 13:25:44 UTC
+++ src/flb_gzip.c
@@ -98,7 +98,7 @@ static inline void flb_hex_dump(uint8_t
         line_length = 40;
     }
 
-    printable_line = alloca(line_length + 1);
+    printable_line = __builtin_alloca(line_length + 1);
 
     if (NULL == printable_line)
     {
