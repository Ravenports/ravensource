--- lib/luajit-2.1.0-1e66d0f/src/lj_prng.c.orig	2021-04-19 23:40:36 UTC
+++ lib/luajit-2.1.0-1e66d0f/src/lj_prng.c
@@ -116,7 +116,7 @@ static PRGR libfunc_rgr;
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
 #elif LJ_TARGET_BSD || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
-#define LJ_TARGET_HAS_GETENTROPY	1
+#define LJ_TARGET_HAS_GETENTROPY	0
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
