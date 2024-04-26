--- lib/fmt/src/fmt.cc.orig	2024-03-10 18:17:39 UTC
+++ lib/fmt/src/fmt.cc
@@ -41,7 +41,7 @@ module;
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #  include <intrin.h>
 #endif
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>
 #endif
 #if __has_include(<winapifamily.h>)
