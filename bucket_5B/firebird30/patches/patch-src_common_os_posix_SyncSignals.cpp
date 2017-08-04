--- src/common/os/posix/SyncSignals.cpp.orig	2017-03-21 09:11:35 UTC
+++ src/common/os/posix/SyncSignals.cpp
@@ -54,9 +54,6 @@
 #include <errno.h>
 #include <unistd.h>
 
-#if defined FREEBSD || defined NETBSD || defined DARWIN || defined HPUX
-#define sigset      signal
-#endif
 
 namespace {
 
