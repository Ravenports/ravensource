--- examples/font.c.orig	2021-10-19 13:58:30 UTC
+++ examples/font.c
@@ -79,7 +79,11 @@ int main(int argc, char *argv[])
 
     {
 #if defined(HAVE_ENDIAN_H)
+ #if defined(__NetBSD__)
+        if(0)
+ #else
         if(__BYTE_ORDER == __BIG_ENDIAN)
+ #endif
 #else
         /* This is compile-time optimised with at least -O1 or -Os */
         uint32_t const tmp = 0x12345678;
