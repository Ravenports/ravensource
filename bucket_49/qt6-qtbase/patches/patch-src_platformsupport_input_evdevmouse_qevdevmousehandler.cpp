--- src/platformsupport/input/evdevmouse/qevdevmousehandler.cpp.orig	2024-11-14 11:02:40 UTC
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
 
