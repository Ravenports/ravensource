NetBSD doesn't define THREAD_STACK_MIN, so pick an arbitrary 16 pages.

--- include/fluent-bit/flb_coro.h.orig	2022-03-22 22:42:32 UTC
+++ include/fluent-bit/flb_coro.h
@@ -65,7 +65,12 @@ struct flb_coro {
 #ifdef FLB_CORO_STACK_SIZE
 #define FLB_CORO_STACK_SIZE      FLB_CORO_STACK_SIZE
 #else
+# if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#include <machine/vmparam.h>
+#define FLB_CORO_STACK_SIZE      (16 * PAGE_SIZE)
+# else
 #define FLB_CORO_STACK_SIZE      ((3 * PTHREAD_STACK_MIN) / 2)
+# endif
 #endif
 
 #define FLB_CORO_DATA(coro)      (((char *) coro) + sizeof(struct flb_coro))
