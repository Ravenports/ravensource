--- lib/fmt/include/fmt/os.h.orig	2024-04-28 10:37:24 UTC
+++ lib/fmt/include/fmt/os.h
@@ -15,7 +15,7 @@
 
 #include "format.h"
 
-#if defined __APPLE__ || defined(__FreeBSD__)
+#if defined __APPLE__ || defined(__FreeBSD__) || defined(__DragonFly__)
 #  if FMT_HAS_INCLUDE(<xlocale.h>)
 #    include <xlocale.h>  // for LC_NUMERIC_MASK on OS X
 #  endif
