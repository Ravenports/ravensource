--- modules/core/include/opencv2/core/utils/filesystem.private.hpp.orig	2017-12-22 19:46:21 UTC
+++ modules/core/include/opencv2/core/utils/filesystem.private.hpp
@@ -10,7 +10,7 @@
 #  if defined(__EMSCRIPTEN__) || defined(__native_client__)
      /* no support */
 #  elif defined __ANDROID__ || defined __linux__ || defined _WIN32 || \
-        defined __FreeBSD__ || defined __bsdi__
+        defined __FreeBSD__ || defined __bsdi__ || defined __DragonFly__
 #      define OPENCV_HAVE_FILESYSTEM_SUPPORT 1
 #  elif defined(__APPLE__)
 #    include <TargetConditionals.h>
