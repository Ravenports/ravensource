Avoid issues with earlier _POSIX_C_SOURCE manipulations on DF and perhaps others.

--- src/io.c.orig	2026-05-26 22:29:56 UTC
+++ src/io.c
@@ -50,7 +50,7 @@ static avif_off_t avif_ftello(FILE * str
 
 #if defined(AVIF_USE_FSEEKO)
 // POSIX large file support
-static_assert(sizeof(off_t) == sizeof(int64_t), "");
+_Static_assert(sizeof(off_t) == sizeof(int64_t), "");
 typedef off_t avif_off_t;
 #define AVIF_OFF_MAX INT64_MAX
 
