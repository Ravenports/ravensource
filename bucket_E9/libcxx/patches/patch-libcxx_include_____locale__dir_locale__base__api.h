--- libcxx/include/__locale_dir/locale_base_api.h.orig	2026-11-02 10:45:15 UTC
+++ libcxx/include/__locale_dir/locale_base_api.h
@@ -110,7 +110,7 @@
 
 #  if defined(__APPLE__)
 #    include <__locale_dir/support/apple.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__DragonFly__)
 #    include <__locale_dir/support/freebsd.h>
 #  elif defined(__NetBSD__)
 #    include <__locale_dir/support/netbsd.h>
