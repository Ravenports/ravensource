--- lib/fmt/src/fmt.cc.orig	2026-04-05 12:50:36 UTC
+++ lib/fmt/src/fmt.cc
@@ -64,7 +64,7 @@ module;
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #  include <intrin.h>
 #endif
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>
 #endif
 #if __has_include(<winapifamily.h>)
