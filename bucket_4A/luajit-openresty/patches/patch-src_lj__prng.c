--- src/lj_prng.c.orig	2022-04-05 12:12:47 UTC
+++ src/lj_prng.c
@@ -109,6 +109,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+# ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX && !LJ_TARGET_IOS
 /*
 ** In their infinite wisdom Apple decided to disallow getentropy() in the
@@ -124,6 +125,7 @@ static PRGR libfunc_rgr;
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
+# endif
 
 #if LJ_TARGET_HAS_GETENTROPY
 extern int getentropy(void *buf, size_t len)
