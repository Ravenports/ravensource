--- external/skia/UnpackedTarball_skia.mk.orig	2025-03-21 15:34:31 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -24,7 +24,6 @@ skia_patches := \
     windows-text-gamma.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -34,6 +33,9 @@ skia_patches := \
     allow-no-es2restrictions.patch.1 \
     vk_mem_alloc.patch.1 \
     macosmetal.patch.1 \
+    netbsd.patch.0 \
+    malloc.patch.0 \
+    SkGetExecutablePath_linux.cpp.patch.0 \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
     fix-SkDebugf-link-error.patch.1 \
