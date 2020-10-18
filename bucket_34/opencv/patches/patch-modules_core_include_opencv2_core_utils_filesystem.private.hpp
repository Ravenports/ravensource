--- modules/core/include/opencv2/core/utils/filesystem.private.hpp.orig	2020-10-11 21:26:07 UTC
+++ modules/core/include/opencv2/core/utils/filesystem.private.hpp
@@ -12,7 +12,7 @@
 #  elif defined WINRT || defined _WIN32_WCE
      /* not supported */
 #  elif defined __ANDROID__ || defined __linux__ || defined _WIN32 || \
-        defined __FreeBSD__ || defined __bsdi__ || defined __HAIKU__
+        defined __FreeBSD__ || defined __bsdi__ || defined __HAIKU__ || defined __DragonFly__ || defined __sun__
 #      define OPENCV_HAVE_FILESYSTEM_SUPPORT 1
 #  elif defined(__APPLE__)
 #    include <TargetConditionals.h>
