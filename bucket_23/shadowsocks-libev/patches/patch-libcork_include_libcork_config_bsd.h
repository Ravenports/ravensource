--- libcork/include/libcork/config/bsd.h.orig	2019-07-24 14:01:14 UTC
+++ libcork/include/libcork/config/bsd.h
@@ -27,7 +27,9 @@
 #error "Cannot determine system endianness"
 #endif
 
+#if !defined(__NetBSD__)
 #define CORK_HAVE_REALLOCF  1
+#endif
 #define CORK_HAVE_PTHREADS  1
 
 
