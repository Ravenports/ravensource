--- libvisual/lv_defines.h.orig	2017-12-25 23:30:22.157273000 +0100
+++ libvisual/lv_defines.h	2017-12-25 23:31:15.040133000 +0100
@@ -63,13 +63,13 @@
 
 /* Compiler specific optimalization macros */
 #if __GNUC__ >= 3
-# define inline			inline __attribute__ ((always_inline))
+# define lv_inline		inline __attribute__ ((always_inline))
 # define __malloc		__attribute__ ((malloc))
 # define __packed		__attribute__ ((packed))
 # define VIS_LIKELY(x)		__builtin_expect (!!(x), 1)
 # define VIS_UNLIKELY(x)	__builtin_expect (!!(x), 0)
 #else
-# define inline			/* no inline */
+# define lv_inline		/* no inline */
 # define __malloc		/* no malloc */
 # define __packed		/* no packed */
 # define VIS_LIKELY(x)		(x)
