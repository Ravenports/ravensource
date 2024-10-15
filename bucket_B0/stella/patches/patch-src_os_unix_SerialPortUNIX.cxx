--- src/os/unix/SerialPortUNIX.cxx.orig	2024-10-07 19:34:18 UTC
+++ src/os/unix/SerialPortUNIX.cxx
@@ -17,7 +17,11 @@
 
 #include <fcntl.h>
 #include <unistd.h>
+#if !defined(__DragonFly__) && !defined(_FreeBSD__)
 #include <sys/termios.h>
+#else
+#include <termios.h>
+#endif
 #include <sys/ioctl.h>
 #include <cstring>
 
