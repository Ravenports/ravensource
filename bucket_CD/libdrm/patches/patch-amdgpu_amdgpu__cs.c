$NetBSD: patch-amdgpu_amdgpu__cs.c,v 1.3 2022/03/13 15:20:01 tnn Exp $

libc-supplied compat alloca(3) should not be used

--- amdgpu/amdgpu_cs.c.orig	2025-06-08 12:27:53 UTC
+++ amdgpu/amdgpu_cs.c
@@ -28,9 +28,7 @@
 #include <pthread.h>
 #include <sched.h>
 #include <sys/ioctl.h>
-#if HAVE_ALLOCA_H
-# include <alloca.h>
-#endif
+#define alloca(size) __builtin_alloca(size)
 
 #include "xf86drm.h"
 #include "amdgpu_drm.h"
