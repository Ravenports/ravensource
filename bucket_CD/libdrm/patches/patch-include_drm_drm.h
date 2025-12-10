--- include/drm/drm.h.orig	2025-11-17 15:17:12 UTC
+++ include/drm/drm.h
@@ -907,7 +907,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef __sun__
+#define DRM_CLOEXEC 0
+#else
 #define DRM_CLOEXEC O_CLOEXEC
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
