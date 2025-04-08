--- common/common.cpp.orig	2024-11-22 12:07:34 UTC
+++ common/common.cpp
@@ -35,6 +35,27 @@
 #include <sys/time.h>
 #endif
 
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
 namespace X265_NS {
 
 #if CHECKED_BUILD || _DEBUG
