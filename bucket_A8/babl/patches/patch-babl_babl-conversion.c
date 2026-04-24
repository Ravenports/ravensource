--- babl/babl-conversion.c.orig	2026-04-09 18:58:59 UTC
+++ babl/babl-conversion.c
@@ -52,8 +52,8 @@ babl_conversion_planar_process (const Ba
   const BablImage *source = (void*)src;
   BablImage       *destination = (void*)dst;
 #ifdef USE_ALLOCA
-  const char **src_data = alloca (sizeof (void *) * source->components);
-  char **dst_data = alloca (sizeof (void *) * destination->components);
+  const char **src_data = __builtin_alloca (sizeof (void *) * source->components);
+  char **dst_data = __builtin_alloca (sizeof (void *) * destination->components);
 #else
   const char  *src_data[BABL_MAX_COMPONENTS];
   char  *dst_data[BABL_MAX_COMPONENTS];
