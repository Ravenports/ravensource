--- libcxx/include/__locale_dir/locale_base_api.h.orig	2026-03-23 18:46:22 UTC
+++ libcxx/include/__locale_dir/locale_base_api.h
@@ -108,7 +108,7 @@
 
 #  if defined(__APPLE__)
 #    include <__locale_dir/support/apple.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__DragonFly__)
 #    include <__locale_dir/support/freebsd.h>
 #  elif defined(__NetBSD__)
 #    include <__locale_dir/support/netbsd.h>
