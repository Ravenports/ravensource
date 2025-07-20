--- 3rdparty/ittnotify/include/ittnotify.h.orig	2025-07-02 07:54:13 UTC
+++ 3rdparty/ittnotify/include/ittnotify.h
@@ -99,7 +99,7 @@ The same ID may not be reused for differ
 #    define ITT_OS ITT_OS_WIN
 #  elif defined( __APPLE__ ) && defined( __MACH__ )
 #    define ITT_OS ITT_OS_MAC
-#  elif defined( __FreeBSD__ )
+#  elif defined( __FreeBSD__ ) || defined __DragonFly__
 #    define ITT_OS ITT_OS_FREEBSD
 #  elif defined( __OpenBSD__)
 #    define ITT_OS ITT_OS_OPENBSD
