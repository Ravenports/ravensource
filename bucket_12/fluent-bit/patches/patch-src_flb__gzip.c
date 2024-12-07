--- src/flb_gzip.c.orig	2024-11-27 17:22:52 UTC
+++ src/flb_gzip.c
@@ -98,7 +98,7 @@ static inline void flb_hex_dump(uint8_t
         line_length = 40;
     }
 
-    printable_line = alloca(line_length + 1);
+    printable_line = __builtin_alloca(line_length + 1);
 
     if (NULL == printable_line)
     {
