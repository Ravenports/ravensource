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
@@ -59,10 +59,27 @@
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
+# ifndef MAP_ANONYMOUS
+#define	MAP_ANONYMOUS MAP_ANON
+# endif
+#define	MMAP2_PAGE_SHIFT 0
+#define	_IOC_NR(cmd) ((cmd) & 0x1FFF)
+#define	_IOC_SIZE(cmd) (((cmd) >> 16) & 0x1FFF)
+#define	_IOC_TYPE(cmd) (((cmd) >> 8) & 0xFF)
+typedef off_t __off_t;
+#endif
+
 #if defined(__OpenBSD__)
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -98,11 +115,11 @@
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
