$NetBSD: patch-mysys_my__largepage.c,v 1.2 2025/10/27 20:56:37 nia Exp $

--- mysys/my_largepage.c.orig	2026-11-17 07:14:00 UTC
+++ mysys/my_largepage.c
@@ -28,6 +28,7 @@
 #endif
 
 #ifdef HAVE_SOLARIS_LARGE_PAGES
+my_bool opt_super_large_pages= 0;
 #if defined(__sun__) && defined(__GNUC__) && defined(__cplusplus) \
     && defined(_XOPEN_SOURCE)
 /* memcntl exist within sys/mman.h, but under-defines what is need to use it */
@@ -206,7 +207,6 @@ int my_init_large_pages(void)
 #endif
 
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-  extern my_bool opt_super_large_pages;
   /*
     tell the kernel that we want to use 4/256MB page for heap storage
     and also for the stack. We use 4 MByte as default and if the
