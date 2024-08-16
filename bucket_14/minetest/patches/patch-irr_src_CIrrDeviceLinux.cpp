From a677d33bdffa110fe611e49e346c0bd99dafb5ca Mon Sep 17 00:00:00 2001
From: Dmitry Marakasov <amdmi3@amdmi3.ru>
Date: Mon, 12 Aug 2024 15:25:57 +0300
Subject: [PATCH] Include unistd.h for getpid() when _IRR_COMPILE_WITH_X11_

---
 irr/src/CIrrDeviceLinux.cpp | 5 ++++-
 1 file changed, 4 insertions(+), 1 deletion(-)

diff --git a/irr/src/CIrrDeviceLinux.cpp b/irr/src/CIrrDeviceLinux.cpp
index 71eb0f2604cd..5491d2037502 100644
--- irr/src/CIrrDeviceLinux.cpp.orig
+++ irr/src/CIrrDeviceLinux.cpp
@@ -45,9 +45,12 @@
 #include <X11/Xcursor/Xcursor.h>
 #endif
 
+#if defined(_IRR_COMPILE_WITH_X11_) || defined(_IRR_COMPILE_WITH_JOYSTICK_EVENTS_)
+#include <unistd.h>
+#endif
+
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
-#include <unistd.h>
 
 #ifdef __FreeBSD__
 #include <sys/joystick.h>
