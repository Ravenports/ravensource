--- src/mkvtoolnix-gui/util/sleep_inhibitor.cpp.orig	2025-04-26 13:52:13 UTC
+++ src/mkvtoolnix-gui/util/sleep_inhibitor.cpp
@@ -6,7 +6,7 @@
 # include "mkvtoolnix-gui/util/sleep_inhibitor/windows.h"
 #elif defined(SYS_APPLE)
 # include "mkvtoolnix-gui/util/sleep_inhibitor/macos.h"
-#elif defined(HAVE_QTDBUS)
+#elif defined(__linux__)
 # include "mkvtoolnix-gui/util/sleep_inhibitor/linux_logind.h"
 #endif
 
@@ -66,7 +66,7 @@ BasicSleepInhibitor::create() {
   inhibitor->addInhibitor(std::make_shared<WindowsSleepInhibitor>());
 #elif defined(SYS_APPLE)
   inhibitor->addInhibitor(std::make_shared<MacOSSleepInhibitor>());
-#elif defined(HAVE_QTDBUS)
+#elif defined(__linux__)
   inhibitor->addInhibitor(std::make_shared<LogindSleepInhibitor>());
 #endif
 
