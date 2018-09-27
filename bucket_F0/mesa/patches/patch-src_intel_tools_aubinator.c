--- src/intel/tools/aubinator.c.orig	2018-09-21 10:57:00 UTC
+++ src/intel/tools/aubinator.c
@@ -47,6 +47,7 @@
 #include "intel_aub.h"
 
 #ifndef HAVE_MEMFD_CREATE
+# ifdef __Linux__
 #include <sys/syscall.h>
 
 static inline int
@@ -54,6 +55,13 @@ memfd_create(const char *name, unsigned
 {
    return syscall(SYS_memfd_create, name, flags);
 }
+# elif defined __FreeBSD__
+static inline int
+memfd_create(const char *name __unused__, unsigned int flags __unused__)
+{
+   return shm_open(SHM_ANON, O_RDWR, 0600);   
+}
+# endif
 #endif
 
 /* Below is the only command missing from intel_aub.h in libdrm
