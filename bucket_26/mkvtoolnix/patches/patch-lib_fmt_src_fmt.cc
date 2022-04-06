--- lib/fmt/src/fmt.cc.orig	2022-03-13 12:54:59 UTC
+++ lib/fmt/src/fmt.cc
@@ -46,7 +46,7 @@ module;
 #if _MSC_VER
 #  include <intrin.h>
 #endif
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>
 #endif
 #if __has_include(<winapifamily.h>)
