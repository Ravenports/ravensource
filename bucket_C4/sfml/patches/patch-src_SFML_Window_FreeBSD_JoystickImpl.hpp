$NetBSD: patch-src_SFML_Window_FreeBSD_JoystickImpl.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/FreeBSD/JoystickImpl.hpp.orig	2023-10-30 00:03:26 UTC
+++ src/SFML/Window/FreeBSD/JoystickImpl.hpp
@@ -28,6 +28,9 @@
 ////////////////////////////////////////////////////////////
 // Headers
 ////////////////////////////////////////////////////////////
+#if defined(__NetBSD__)
+#include <dev/usb/usb.h>
+#endif
 #include <dev/usb/usbhid.h>
 #include <usbhid.h>
 #include <vector>
