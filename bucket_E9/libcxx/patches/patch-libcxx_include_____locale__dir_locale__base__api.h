--- libcxx/include/__locale_dir/locale_base_api.h.orig	2025-12-01 12:58:50 UTC
+++ libcxx/include/__locale_dir/locale_base_api.h
@@ -113,7 +113,7 @@
 
 #  if defined(__APPLE__)
 #    include <__locale_dir/support/apple.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__DragonFly__)
 #    include <__locale_dir/support/freebsd.h>
 #  elif defined(_LIBCPP_MSVCRT_LIKE)
 #    include <__locale_dir/support/windows.h>
