- Define ETIME if missing

--- src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c.orig	2021-04-21 17:41:10 UTC
+++ src/amd/vulkan/winsys/amdgpu/radv_amdgpu_cs.c
@@ -36,6 +36,9 @@
 #include "radv_amdgpu_bo.h"
 #include "sid.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 enum {
 	VIRTUAL_BUFFER_HASH_TABLE_SIZE = 1024
