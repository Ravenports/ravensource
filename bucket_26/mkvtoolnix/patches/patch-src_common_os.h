--- src/common/os.h.orig	2024-10-19 13:14:27 UTC
+++ src/common/os.h
@@ -21,7 +21,7 @@
 #else
 # define COMP_GCC
 # define SYS_UNIX
-# if defined(__bsdi__) || defined(__FreeBSD__)
+# if defined(__bsdi__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #  define SYS_BSD
 # elif defined(__sun) && defined(__SUNPRO_CC)
 #  undef COMP_GCC
