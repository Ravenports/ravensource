--- src/corelib/corelib.pro.orig	2020-12-04 10:14:27 UTC
+++ src/corelib/corelib.pro
@@ -32,7 +32,7 @@ ANDROID_PERMISSIONS = \
 # QtCore can't be compiled with -Wl,-no-undefined because it uses the "environ"
 # variable and on FreeBSD and OpenBSD, this variable is in the final executable itself.
 # OpenBSD 6.0 will include environ in libc.
-freebsd|openbsd: QMAKE_LFLAGS_NOUNDEF =
+freebsd|openbsd|dragonfly: QMAKE_LFLAGS_NOUNDEF =
 
 qtConfig(animation): include(animation/animation.pri)
 include(global/global.pri)
