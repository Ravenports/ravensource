--- lib/fmt/src/fmt.cc.orig	2025-11-08 10:22:34 UTC
+++ lib/fmt/src/fmt.cc
@@ -60,7 +60,7 @@ module;
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #  include <intrin.h>
 #endif
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>
 #endif
 #if __has_include(<winapifamily.h>)
