--- lib/fmt/include/fmt/os.h.orig	2023-08-20 09:03:28 UTC
+++ lib/fmt/include/fmt/os.h
@@ -13,7 +13,7 @@
 #include <cstdio>
 #include <system_error>  // std::system_error
 
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>  // for LC_NUMERIC_MASK on OS X
 #endif
 
