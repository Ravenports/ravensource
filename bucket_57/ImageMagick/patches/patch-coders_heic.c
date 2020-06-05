From a6a1e0616b6c431b55ed255454144653dd677d21 Mon Sep 17 00:00:00 2001
From: Emily Bowman <silverbacknet@gmail.com>
Date: Thu, 4 Jun 2020 04:22:06 -0700
Subject: [PATCH] Correct AVIF creation call

---
 coders/heic.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/coders/heic.c b/coders/heic.c
index 3f36d5c656..1f454146f9 100644
--- coders/heic.c
+++ coders/heic.c
@@ -942,7 +942,7 @@ static MagickBooleanType WriteHEICImage(const ImageInfo *image_info,
 #if LIBHEIF_NUMERIC_VERSION > 0x01060200
     if (LocaleCompare(image_info->magick,"AVIF") == 0)
       error=heif_context_get_encoder_for_format(heif_context,
-        heif_compression_AVIF,&heif_encoder);
+        heif_compression_AV1,&heif_encoder);
 #endif
     status=IsHeifSuccess(&error,image,exception);
     if (status == MagickFalse)
