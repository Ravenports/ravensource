--- babl/babl-fish-path.c.orig	2026-04-09 18:58:59 UTC
+++ babl/babl-fish-path.c
@@ -1544,14 +1544,14 @@ process_conversion_path (BablList   *pat
     {
       long j;
 
-      void *temp_buffer = align_16 (alloca (MIN(n, MAX_BUFFER_SIZE) *
+      void *temp_buffer = align_16 (__builtin_alloca (MIN(n, MAX_BUFFER_SIZE) *
                                     sizeof (double) * 5 + 16));
       void *temp_buffer2 = NULL;
 
       if (conversions > 2)
         {
           /* We'll need one more auxiliary buffer */
-          temp_buffer2 = align_16 (alloca (MIN(n, MAX_BUFFER_SIZE) *
+          temp_buffer2 = align_16 (__builtin_alloca (MIN(n, MAX_BUFFER_SIZE) *
                                    sizeof (double) * 5 + 16));
         }
 
