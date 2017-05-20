--- compat/bsd_compat.h.orig	2017-05-16 10:02:56.425060136 -0500
+++ compat/bsd_compat.h	2017-05-16 10:11:34.539069691 -0500
@@ -37,6 +37,10 @@
  #endif
 #endif
 
+#ifndef	__DECONST
+#define	__DECONST(type, var)	((type)(uintptr_t)(const void *)(var))
+#endif
+
 #ifdef HAVE_BSD_SYS_CDEFS_H
 #include <bsd/sys/cdefs.h>
 #endif
