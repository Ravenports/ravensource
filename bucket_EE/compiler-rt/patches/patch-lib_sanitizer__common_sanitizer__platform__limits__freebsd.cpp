--- lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp.orig	2022-01-20 21:31:59 UTC
+++ lib/sanitizer_common/sanitizer_platform_limits_freebsd.cpp
@@ -71,7 +71,6 @@
 #include <stddef.h>
 #include <stdio.h>
 #include <stringlist.h>
-#include <term.h>
 #include <termios.h>
 #include <time.h>
 #include <utime.h>
