Fix build with jpeg-turbo 3.0.0

--- coders/jpeg.c.orig	2022-12-26 16:56:04 UTC
+++ coders/jpeg.c
@@ -954,7 +954,7 @@ EstimateJPEGQuality(const struct jpeg_de
     i;
 
   save_quality=0;
-#ifdef D_LOSSLESS_SUPPORTED
+#if 0
   if (image->compression==LosslessJPEGCompression)
     {
       save_quality=100;
@@ -1461,7 +1461,7 @@ static Image *ReadJPEGImage(const ImageI
     }
 #endif
 #if (JPEG_LIB_VERSION >= 61) && defined(D_PROGRESSIVE_SUPPORTED)
-#ifdef D_LOSSLESS_SUPPORTED
+#if 0
   image->interlace=
     jpeg_info.process == JPROC_PROGRESSIVE ? LineInterlace : NoInterlace;
   image->compression=jpeg_info.process == JPROC_LOSSLESS ?
@@ -2896,7 +2896,7 @@ static MagickPassFail WriteJPEGImage(con
   if ((image->compression == LosslessJPEGCompression) ||
       (quality > 100))
     {
-#if defined(C_LOSSLESS_SUPPORTED)
+#if 0
       if (quality < 100)
         ThrowException(&image->exception,CoderWarning,
                        LosslessToLossyJPEGConversion,(char *) NULL);
