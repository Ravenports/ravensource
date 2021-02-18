--- lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp.orig	2021-02-03 21:51:10 UTC
+++ lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp
@@ -68,7 +68,6 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <stringlist.h>
-#include <term.h>
 #include <termios.h>
 #include <time.h>
 #include <utime.h>
