--- lib/fmt/include/fmt/os.h.orig	2022-04-10 13:55:56 UTC
+++ lib/fmt/include/fmt/os.h
@@ -15,7 +15,7 @@
 #include <cstdlib>       // strtod_l
 #include <system_error>  // std::system_error
 
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <xlocale.h>  // for LC_NUMERIC_MASK on OS X
 #endif
 
