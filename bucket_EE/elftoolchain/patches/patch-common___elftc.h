--- common/_elftc.h.orig	2015-08-31 19:53:08 UTC
+++ common/_elftc.h
@@ -295,7 +295,7 @@ struct name {							\
 #endif
 
 #if defined(__APPLE__) || defined(__GLIBC__) || defined(__GNU__) || \
-    defined(__linux__)
+    defined(__linux__) || defined(__sun__)
 #if defined(__GNUC__)
 #define	ELFTC_VCSID(ID)		__asm__(".ident\t\"" ID "\"")
 #else
@@ -365,6 +365,9 @@ extern const char *__progname;
 
 #endif	/* ELFTC_GETPROGNAME */
 
+#ifdef __sun__
+#define ELFTC_GETPROGNAME()	getexecname
+#endif
 
 /**
  ** Per-OS configuration.
@@ -481,4 +484,20 @@ extern const char *__progname;
 
 #endif	/* __OpenBSD__ */
 
+#ifdef __sun__
+
+#define roundup(x, y)	((((x)+((y)-1))/(y))*(y))  /* to any y */
+#define roundup2(x, y)	(((x)+((y)-1))&(~((y)-1))) /* if y is powers of two */
+
+
+
+#define	ELFTC_BYTE_ORDER			__BYTE_ORDER
+#define	ELFTC_BYTE_ORDER_LITTLE_ENDIAN		__LITTLE_ENDIAN
+#define	ELFTC_BYTE_ORDER_BIG_ENDIAN		__BIG_ENDIAN
+#define	ELFTC_HAVE_MMAP				1
+#define	ELFTC_HAVE_STRMODE			0
+#define	ELFTC_NEED_BYTEORDER_EXTENSIONS		1
+
+#endif /* __sun__ */
+
 #endif	/* _ELFTC_H */
