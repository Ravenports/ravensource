--- src/stratagus/util.cpp.orig	2026-10-24 18:53:23.302874000 +0200
+++ src/stratagus/util.cpp	2026-10-24 18:57:44.946029000 +0200
@@ -41,7 +41,9 @@
 #include <stdlib.h>
 #include <stdarg.h>
 
+#ifdef LINUX
 #include <malloc.h>
+#endif
 #ifdef WIN32
 #include <windows.h>
 #include <intrin.h>
@@ -632,10 +634,18 @@
 {
 #ifdef WIN32
 	return _aligned_malloc(size, alignment);
-#elif _ISOC11_SOURCE
+#elif HAVE_ALIGNED_ALLOC
 	return aligned_alloc(alignment, size);
-#else
+#elif HAVE_POSIX_MEMALIGN
+	void *ptr = nullptr;
+	if (posix_memalign(&ptr, alignment, size) != 0) {
+		return nullptr;
+	}
+	return ptr;
+#elif HAVE_MEMALIGN
 	return memalign(alignment, size);
+#else
+#error "No aligned memory allocation function available"
 #endif
 }
 
