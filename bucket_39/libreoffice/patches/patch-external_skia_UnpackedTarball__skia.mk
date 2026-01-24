--- external/skia/UnpackedTarball_skia.mk.orig	2026-01-14 23:16:14 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -23,7 +23,6 @@ skia_patches := \
     windows-do-not-modify-logfont.patch.0 \
     windows-force-unicode-api.patch.0 \
     fix-without-gl.patch.1 \
-    windows-typeface-directwrite.patch.1 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
     swap-buffers-rect.patch.1 \
@@ -33,6 +32,9 @@ skia_patches := \
     allow-no-es2restrictions.patch.1 \
     vk_mem_alloc.patch.1 \
     macosmetal.patch.1 \
+    netbsd.patch.0 \
+    malloc.patch.0 \
+    SkGetExecutablePath_linux.cpp.patch.0 \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
     fix-SkDebugf-link-error.patch.1 \
