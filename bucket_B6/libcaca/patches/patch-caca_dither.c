--- caca/dither.c.orig	2021-10-19 13:58:30 UTC
+++ caca/dither.c
@@ -1324,7 +1324,11 @@ static void get_rgba_default(caca_dither
         case 3:
         {
 #if defined(HAVE_ENDIAN_H)
+  #if defined(__NetBSD__)
+            if(0)
+  #else
             if(__BYTE_ORDER == __BIG_ENDIAN)
+  #endif
 #else
             /* This is compile-time optimised with at least -O1 or -Os */
             uint32_t const tmp = 0x12345678;
