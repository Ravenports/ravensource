--- src/common/os.h.orig	2021-01-30 15:09:14 UTC
+++ src/common/os.h
@@ -24,7 +24,7 @@
 #else
 # define COMP_GCC
 # define SYS_UNIX
-# if defined(__bsdi__) || defined(__FreeBSD__)
+# if defined(__bsdi__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #  define SYS_BSD
 # elif defined(__sun) && defined(__SUNPRO_CC)
 #  undef COMP_GCC
