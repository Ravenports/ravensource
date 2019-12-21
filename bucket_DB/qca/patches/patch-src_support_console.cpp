--- src/support/console.cpp.orig	2019-04-24 12:58:14 UTC
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
