--- lib/vmalloc/vmhdr.h.orig	2018-07-24 18:21:09 UTC
+++ lib/vmalloc/vmhdr.h
@@ -20,6 +20,10 @@ extern "C" {
 #ifndef _BLD_vmalloc
 #define _BLD_vmalloc	1
 #endif
+#if defined(__FreeBSD__) && defined(__aarch64__)
+/* No sbrk on FreeBSD/AArch64 */
+#define _std_malloc	1
+#endif
 #ifdef _WIN32
 #include <io.h>
 #endif
