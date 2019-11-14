- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2019-11-13 18:45:06 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -35,6 +35,9 @@
 #include "radv_amdgpu_bo.h"
 #include "sid.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 enum {
 	VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024
