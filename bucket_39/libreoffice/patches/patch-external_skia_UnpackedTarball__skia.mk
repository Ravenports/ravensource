--- external/skia/UnpackedTarball_skia.mk.orig	2021-08-16 19:56:28 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,7 @@ skia_patches := \
     fast-png-write.patch.1 \
     skia_sk_cpu_sse_level_0_by_default.patch.1 \
     fix-warnings.patch.1 \
+    jrm-fix.patch
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
