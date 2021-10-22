--- aacenc/basic_op/typedefs.h.orig	2012-06-03 21:02:10 UTC
+++ aacenc/basic_op/typedefs.h
@@ -48,7 +48,9 @@
 #define assert(_Expression)     ((void)0)
 #endif
 
+#if !defined __NetBSD__
 #define __inline static __inline
+#endif
 
 #define INT_BITS   32
 /*
