--- lib/luajit-2.1.0-dd5032e/src/lj_prng.c.orig	2020-12-18 00:40:07 UTC
+++ lib/luajit-2.1.0-dd5032e/src/lj_prng.c
@@ -116,7 +116,7 @@ static PRGR libfunc_rgr;
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
 #elif LJ_TARGET_BSD || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
-#define LJ_TARGET_HAS_GETENTROPY	1
+#define LJ_TARGET_HAS_GETENTROPY	0
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
