Support HDF5 version 2.0+

--- libhdf5/H5FDhttp.h.orig	2025-02-07 21:40:00 UTC
+++ libhdf5/H5FDhttp.h
@@ -31,7 +31,7 @@
 
 #if H5_VERSION_GE(1,13,2)
 #define H5_VFD_HTTP     ((H5FD_class_value_t)(514))
-#define H5FD_HTTP	(H5FDperform_init(H5FD_http_init))
+#define H5FD_HTTP	(H5OPEN H5FD_http_init())
 #else
 #define H5FD_HTTP	(H5FD_http_init())
 #endif
