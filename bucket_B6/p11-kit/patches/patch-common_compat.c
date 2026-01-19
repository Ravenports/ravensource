--- common/compat.c.orig	2024-03-07 14:46:09 UTC
+++ common/compat.c
@@ -41,18 +41,6 @@
  * This is excluded on SunOS due to it making the code compile in < XPG6 mode
  * which is not supported with a C99 compiler.
  */
-#ifndef __sun
-#define _XOPEN_SOURCE 700
-#endif
-
-/*
- * This is needed to expose issetugid, getresuid, and getresgid, which are
- * hidden with the _XOPEN_SOURCE setting above
- */
-#ifdef __FreeBSD__
-#undef __BSD_VISIBLE
-#define __BSD_VISIBLE 1
-#endif
 
 #include "compat.h"
 #include "debug.h"
@@ -876,7 +864,7 @@ _p11_getauxval (unsigned long type)
 		secure = __libc_enable_secure;
 
 #elif defined(HAVE_ISSETUGID) && \
-	!((defined __APPLE__ && defined __MACH__) || (defined __FreeBSD__))
+	!((defined __APPLE__ && defined __MACH__))
 		secure = issetugid ();
 
 #elif defined(OS_UNIX)
