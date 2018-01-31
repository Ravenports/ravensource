--- contrib/freebsd/include/linux/input.h.orig	2015-05-06 19:24:59 UTC
+++ contrib/freebsd/include/linux/input.h
@@ -42,10 +42,16 @@ typedef int8_t __s8;
 #endif
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #define __user
 #define	_IOC_READ   IOC_OUT
 #define	_IOC_WRITE  IOC_IN
+#elif defined __sun__
+#define __user
+#include <sys/ioccom.h>
+#define	_IOC_READ   IOC_OUT
+#define	_IOC_WRITE  IOC_IN
+#define	_IOC(inout,group,num,len)	((unsigned long) ((inout) | (((len) & IOCPARM_MASK) << 16) | ((group) << 8) | (num)))
 #else
 #include <linux/types.h>
 #endif
