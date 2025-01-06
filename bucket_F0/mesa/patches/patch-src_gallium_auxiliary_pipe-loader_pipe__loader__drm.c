--- src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2025-01-03 17:37:20 UTC
+++ src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c
@@ -36,6 +36,7 @@
 #include <xf86drm.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <stdbool.h>
 
 #include "loader.h"
 #include "target-helpers/drm_helper_public.h"
