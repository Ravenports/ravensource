$NetBSD: patch-src_SFML_Window_FreeBSD_JoystickImpl.hpp,v 1.1 2020/05/21 08:42:00 plunky Exp $

add NetBSD support

--- src/SFML/Window/FreeBSD/JoystickImpl.hpp.orig	2025-04-22 13:06:02 UTC
+++ src/SFML/Window/FreeBSD/JoystickImpl.hpp
@@ -27,6 +27,9 @@
 ////////////////////////////////////////////////////////////
 // Headers
 ////////////////////////////////////////////////////////////
+#if defined(__NetBSD__)
+#include <dev/usb/usb.h>
+#endif
 #include <dev/usb/usbhid.h>
 #include <usbhid.h>
 #include <vector>
