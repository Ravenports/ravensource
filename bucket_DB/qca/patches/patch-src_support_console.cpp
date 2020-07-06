--- src/support/console.cpp.orig	2020-07-06 09:43:51 UTC
+++ src/support/console.cpp
@@ -30,7 +30,7 @@
 #ifdef Q_OS_WIN
 # include <windows.h>
 #else
-# ifdef Q_OS_ANDROID
+# if defined(Q_OS_ANDROID) || defined(Q_OS_FREEBSD)
 #  include <termios.h>
 # else
 #  include <sys/termios.h>
