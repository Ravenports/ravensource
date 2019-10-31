--- src/platformsupport/input/evdevmouse/qevdevmousehandler.cpp.orig	2019-08-31 08:29:31 UTC
+++ src/platformsupport/input/evdevmouse/qevdevmousehandler.cpp
@@ -53,12 +53,7 @@
 
 #include <errno.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
-#include <linux/kd.h>
 #include <linux/input.h>
-#endif
 
 #define TEST_BIT(array, bit)    (array[bit/8] & (1<<(bit%8)))
 
