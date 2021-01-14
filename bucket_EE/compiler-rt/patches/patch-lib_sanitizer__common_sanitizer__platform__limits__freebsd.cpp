--- lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp.orig	2020-12-18 19:57:38 UTC
+++ lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp
@@ -68,7 +68,6 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <stringlist.h>
-#include <term.h>
 #include <termios.h>
 #include <time.h>
 #include <utime.h>
