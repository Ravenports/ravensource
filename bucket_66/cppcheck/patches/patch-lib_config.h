--- lib/config.h.orig	2026-03-26 14:47:34 UTC
+++ lib/config.h
@@ -206,7 +206,7 @@
 #define USE_WINDOWS_SEH
 #endif
 
-#if !defined(NO_UNIX_BACKTRACE_SUPPORT) && defined(__GNUC__) && !defined(__APPLE__) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__SVR4) && !defined(__QNX__) && !defined(_AIX)
+#if !defined(NO_UNIX_BACKTRACE_SUPPORT) && defined(__linuxC__)
 #define USE_UNIX_BACKTRACE_SUPPORT
 #endif
 
