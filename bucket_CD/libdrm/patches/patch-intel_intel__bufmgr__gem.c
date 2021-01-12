--- intel/intel_bufmgr_gem.c.orig	2021-01-11 18:15:27 UTC
+++ intel/intel_bufmgr_gem.c
@@ -1005,6 +1005,27 @@ drm_intel_gem_bo_alloc_userptr(drm_intel
 	return &bo_gem->bo;
 }
 
+#ifdef __sun__
+#define posix_memalign	illumos_memalign
+static int
+posix_memalign(void **memptr, size_t alignment, size_t size)
+{
+	void *ptr = NULL;
+	int error = 0;
+
+	if (alignment == 0 ||
+	    (alignment & (sizeof (void *) - 1)) != 0 ||
+	    (alignment & (alignment - 1)) != 0)
+		error = EINVAL;
+	else if (size != 0 &&
+	    (ptr = memalign(alignment, size)) == NULL)
+		error = ENOMEM;
+
+	*memptr = ptr;
+	return (error);
+}
+#endif
+
 static bool
 has_userptr(drm_intel_bufmgr_gem *bufmgr_gem)
 {
