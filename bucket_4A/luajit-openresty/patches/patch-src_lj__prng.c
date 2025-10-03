--- src/lj_prng.c.orig	2025-05-29 05:19:55 UTC
+++ src/lj_prng.c
@@ -113,6 +113,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+# ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX && !LJ_TARGET_IOS
 /*
 ** In their infinite wisdom Apple decided to disallow getentropy() in the
@@ -128,6 +129,7 @@ static PRGR libfunc_rgr;
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN || LJ_TARGET_QNX
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
+# endif
 
 #if LJ_TARGET_HAS_GETENTROPY
 extern int getentropy(void *buf, size_t len)
