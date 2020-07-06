--- src/common/os/posix/SyncSignals.cpp.orig	2020-06-26 08:30:29 UTC
+++ src/common/os/posix/SyncSignals.cpp
@@ -54,9 +54,6 @@
 #include <errno.h>
 #include <unistd.h>
 
-#if defined FREEBSD || defined NETBSD || defined DARWIN || defined HPUX
-#define sigset      signal
-#endif
 
 namespace {
 
