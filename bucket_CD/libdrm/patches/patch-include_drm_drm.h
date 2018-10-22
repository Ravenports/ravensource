--- include/drm/drm.h.orig	2018-10-16 14:49:03 UTC
+++ include/drm/drm.h
@@ -697,7 +697,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef __sun__
+#define DRM_CLOEXEC 0
+#else
 #define DRM_CLOEXEC O_CLOEXEC
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
