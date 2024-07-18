--- external/skia/UnpackedTarball_skia.mk.orig	2024-07-10 15:12:43 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -34,6 +34,8 @@ skia_patches := \
     allow-no-es2restrictions.patch.1 \
     vk_mem_alloc.patch.1 \
     tdf147342.patch.0 \
+    netbsd.patch.0 \
+    SkContainers.cpp.patch.0 \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
     fix-SkDebugf-link-error.patch.1 \
