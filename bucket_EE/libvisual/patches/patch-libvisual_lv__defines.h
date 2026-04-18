--- libvisual/lv_defines.h.orig	2023-03-20 02:04:17 UTC
+++ libvisual/lv_defines.h
@@ -64,7 +64,9 @@
 /* Compiler specific optimalization macros */
 #if __GNUC__ >= 3
 # define __malloc		__attribute__ ((malloc))
+#  if !defined(__sun)
 # define __packed		__attribute__ ((packed))
+#  endif
 # define VIS_LIKELY(x)		__builtin_expect (!!(x), 1)
 # define VIS_UNLIKELY(x)	__builtin_expect (!!(x), 0)
 #else
