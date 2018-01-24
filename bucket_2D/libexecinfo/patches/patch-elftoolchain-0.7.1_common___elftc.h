--- ../elftoolchain-0.7.1/common/_elftc.h.orig	2015-08-31 19:53:08 UTC
+++ ../elftoolchain-0.7.1/common/_elftc.h
@@ -294,6 +294,10 @@ struct name {							\
 #define	ELFTC_VCSID(ID)		__FBSDID(ID)
 #endif
 
+#if defined(__sun__)
+#define	ELFTC_VCSID(ID)		/**/
+#endif
+
 #if defined(__APPLE__) || defined(__GLIBC__) || defined(__GNU__) || \
     defined(__linux__)
 #if defined(__GNUC__)
@@ -332,7 +336,7 @@ struct name {							\
 #ifndef	ELFTC_GETPROGNAME
 
 #if defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
-    defined(__minix) || defined(__NetBSD__)
+    defined(__minix) || defined(__NetBSD__) || defined(__sun__)
 
 #include <stdlib.h>
 
@@ -400,6 +404,15 @@ extern const char *__progname;
 
 #endif
 
+#if defined(__sun__)
+#define ELFTC_BYTE_ORDER			1234
+#define ELFTC_BYTE_ORDER_LITTLE_ENDIAN		1234
+#define ELFTC_BYTE_ORDER_BIG_ENDIAN		4321
+#define ELFTC_HAVE_MMAP				1
+#define roundup(x, y)		((((x)+((y)-1))/(y))*(y))
+#define roundup2(x, y)		(((x)+((y)-1))&(~((y)-1)))
+#endif
+ 
 #if defined(__GLIBC__) || defined(__linux__)
 
 #include <endian.h>
