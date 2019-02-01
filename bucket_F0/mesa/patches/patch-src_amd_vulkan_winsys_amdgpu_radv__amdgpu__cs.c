- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2019-01-31 21:05:07 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -35,6 +35,9 @@
 #include "radv_amdgpu_bo.h"
 #include "sid.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 enum {
 	VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024
