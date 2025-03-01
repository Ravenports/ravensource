NetBSD doesn't define THREAD_STACK_MIN, so pick an arbitrary 16 pages.

--- lib/monkey/include/monkey/mk_thread_libco.h.orig	2025-02-25 13:27:54 UTC
+++ lib/monkey/include/monkey/mk_thread_libco.h
@@ -51,7 +51,12 @@ struct mk_thread {
     void (*cb_destroy) (void *);
 };
 
+#if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#include <machine/vmparam.h>
+#define MK_THREAD_STACK_SIZE      (16 * PAGE_SIZE)
+#else
 #define MK_THREAD_STACK_SIZE      ((3 * PTHREAD_STACK_MIN) / 2)
+#endif
 #define MK_THREAD_DATA(th)        (((char *) th) + sizeof(struct mk_thread))
 
 extern MK_EXPORT MK_TLS_DEFINE(struct mk_thread, mk_thread);
