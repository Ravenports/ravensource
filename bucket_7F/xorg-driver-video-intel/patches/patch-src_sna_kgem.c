--- src/sna/kgem.c.orig	2021-01-15 20:59:05 UTC
+++ src/sna/kgem.c
@@ -71,7 +71,11 @@ search_snoop_cache(struct kgem *kgem, un
 #define DBG_NO_USERPTR 0
 #define DBG_NO_UNSYNCHRONIZED_USERPTR 0
 #define DBG_NO_COHERENT_MMAP_GTT 0
+#if defined __DragonFLy__
+#define DBG_NO_LLC 1
+#else
 #define DBG_NO_LLC 0
+#endif
 #define DBG_NO_SEMAPHORES 0
 #define DBG_NO_MADV 0
 #define DBG_NO_UPLOAD_CACHE 0
@@ -1189,13 +1193,18 @@ static int gem_param(struct kgem *kgem,
 static bool test_has_execbuffer2(struct kgem *kgem)
 {
 	struct drm_i915_gem_execbuffer2 execbuf;
+	int ret;
 
 	memset(&execbuf, 0, sizeof(execbuf));
 	execbuf.buffer_count = 1;
 
-	return do_ioctl(kgem->fd,
-			 DRM_IOCTL_I915_GEM_EXECBUFFER2,
-			 &execbuf) == -EFAULT;
+	ret = do_ioctl(kgem->fd, DRM_IOCTL_I915_GEM_EXECBUFFER2, &execbuf);
+#ifdef __FreeBSD__
+	/* XXX FreeBSD returns ENOENT instead of EFAULT. */
+	if (ret == -ENOENT)
+		return true;
+#endif
+	return ret == -EFAULT;
 }
 
 static bool test_has_no_reloc(struct kgem *kgem)
