--- modules/core/include/opencv2/core/utils/filesystem.private.hpp.orig	2024-06-02 11:41:07 UTC
+++ modules/core/include/opencv2/core/utils/filesystem.private.hpp
@@ -13,6 +13,7 @@
      /* not supported */
 #  elif defined __ANDROID__ || defined __linux__ || defined _WIN32 || \
         defined __FreeBSD__ || defined __bsdi__ || defined __HAIKU__ || \
+	defined __DragonFly__ || defined __sun__ || defined __NetBSD__ || \
         defined __GNU__
 #      define OPENCV_HAVE_FILESYSTEM_SUPPORT 1
 #  elif defined(__APPLE__)
