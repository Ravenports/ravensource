--- lib/libv4lconvert/libv4lsyscall-priv.h.orig	2023-02-24 16:40:23 UTC
+++ lib/libv4lconvert/libv4lsyscall-priv.h
@@ -51,7 +51,7 @@
 #endif
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/time.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -59,10 +59,44 @@
 #define	_IOC_NR(cmd) ((cmd) & 0xFF)
 #define	_IOC_TYPE(cmd) IOCGROUP(cmd)
 #define	_IOC_SIZE(cmd) IOCPARM_LEN(cmd)
+# ifndef MAP_ANONYMOUS
 #define	MAP_ANONYMOUS MAP_ANON
+# endif
 #define	MMAP2_PAGE_SHIFT 0
 #endif
 
+#ifdef __sun__
+#include <sys/time.h>
+#include <sys/syscall.h>
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/ioccom.h>
+#include <sys/mman.h>
+#define	MMAP2_PAGE_SHIFT 0
+/* Linux-style ioctl encoding macros for compatibility */
+# undef _IOC
+# undef _IOR
+# undef _IOW
+# undef _IOWR
+# undef _IOC_TYPE
+# undef _IOC_SIZE
+# define _IOC(dir,type,nr,size) \
+    ((unsigned int)(((dir) << 30) | ((type) << 8) | ((nr) << 0) | ((size) << 16)))
+# define _IOR(type,nr,size)     _IOC(2U, (type), (nr), sizeof(size))
+# define _IOW(type,nr,size)     _IOC(1U, (type), (nr), sizeof(size))
+# define _IOWR(type,nr,size)    _IOC(3U, (type), (nr), sizeof(size))
+# define _IOC_NR(cmd) ((unsigned int)(cmd) & 0xFF)
+# define _IOC_TYPE(cmd) (((cmd) >> 8) & 0xFF)
+# define _IOC_SIZE(cmd) (((cmd) >> 16) & 0x3FFF)
+# ifndef MAP_ANONYMOUS
+#  define MAP_ANONYMOUS MAP_ANON
+# endif
+# ifndef __off_t_defined
+   typedef off_t __off_t;
+#  define __off_t_defined
+# endif
+#endif
+
 #if defined(__OpenBSD__)
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -98,11 +132,11 @@
 #define SYS_WRITE(fd, buf, len) \
 	syscall(SYS_write, (int)(fd), (const void *)(buf), (size_t)(len));
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined (__DragonFly__) || defined(__NetBSD__)
 #define SYS_MMAP(addr, len, prot, flags, fd, off) \
 	__syscall(SYS_mmap, (void *)(addr), (size_t)(len), \
 			(int)(prot), (int)(flags), (int)(fd), (off_t)(off))
-#elif defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD_kernel__) || defined (__sun__)
 #define SYS_MMAP(addr, len, prot, flags, fd, off) \
 	syscall(SYS_mmap, (void *)(addr), (size_t)(len), \
 			(int)(prot), (int)(flags), (int)(fd), (off_t)(off))
