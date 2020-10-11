--- CL/cl_version.h.orig	2020-06-09 17:49:23 UTC
+++ CL/cl_version.h
@@ -19,8 +19,8 @@
 
 /* Detect which version to target */
 #if !defined(CL_TARGET_OPENCL_VERSION)
-#pragma message("cl_version.h: CL_TARGET_OPENCL_VERSION is not defined. Defaulting to 220 (OpenCL 2.2)")
-#define CL_TARGET_OPENCL_VERSION 220
+#pragma message("cl_version.h: CL_TARGET_OPENCL_VERSION is not defined. Defaulting to 300 (OpenCL 3.0)")
+#define CL_TARGET_OPENCL_VERSION 300
 #endif
 #if CL_TARGET_OPENCL_VERSION != 100 && \
     CL_TARGET_OPENCL_VERSION != 110 && \
