--- src/miniacc.h.orig	2017-08-10 11:19:45 UTC
+++ src/miniacc.h
@@ -524,7 +524,7 @@
 #  if defined(_AIX) || defined(__AIX__) || defined(__aix__)
 #    define ACC_OS_POSIX_AIX        1
 #    define ACC_INFO_OS_POSIX       "aix"
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined __DragonFly__
 #    define ACC_OS_POSIX_FREEBSD    1
 #    define ACC_INFO_OS_POSIX       "freebsd"
 #  elif defined(__hpux__) || defined(__hpux)
