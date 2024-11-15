--- src/platformsupport/input/evdevmouse/qevdevmousehandler.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/platformsupport/input/evdevmouse/qevdevmousehandler.cpp
@@ -17,12 +17,7 @@
 
 #include <errno.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
-#include <linux/kd.h>
 #include <linux/input.h>
-#endif
 
 #define TEST_BIT(array, bit)    (array[bit/8] & (1<<(bit%8)))
 
