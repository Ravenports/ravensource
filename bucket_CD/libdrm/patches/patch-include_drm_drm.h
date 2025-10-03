--- include/drm/drm.h.orig	2025-06-08 12:27:53 UTC
+++ include/drm/drm.h
@@ -876,7 +876,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef __sun__
+#define DRM_CLOEXEC 0
+#else
 #define DRM_CLOEXEC O_CLOEXEC
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
