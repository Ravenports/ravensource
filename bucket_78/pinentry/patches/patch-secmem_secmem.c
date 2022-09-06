--- secmem/secmem.c.orig	2022-08-24 10:31:59 UTC
+++ secmem/secmem.c
@@ -85,7 +85,7 @@ log_fatal(char *template, ...)
 #  define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define DEFAULT_POOLSIZE 16384
+#define DEFAULT_POOLSIZE 16384*4
 
 typedef struct memblock_struct MEMBLOCK;
 struct memblock_struct {
