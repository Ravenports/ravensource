--- modules/core/include/opencv2/core/utils/filesystem.private.hpp.orig	2025-07-02 07:54:13 UTC
+++ modules/core/include/opencv2/core/utils/filesystem.private.hpp
@@ -13,6 +13,7 @@
      /* not supported */
 #  elif defined __ANDROID__ || defined __linux__ || defined _WIN32 || defined __CYGWIN__ || \
         defined __FreeBSD__ || defined __bsdi__ || defined __HAIKU__ || \
+        defined __DragonFly__ || defined __sun__ || defined __NetBSD__ || \
         defined __GNU__ || defined __QNX__
 #      define OPENCV_HAVE_FILESYSTEM_SUPPORT 1
 #  elif defined(__APPLE__)
