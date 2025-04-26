--- src/mkvtoolnix-gui/util/sleep_inhibitor/linux_logind.cpp.orig	2025-04-26 13:52:13 UTC
+++ src/mkvtoolnix-gui/util/sleep_inhibitor/linux_logind.cpp
@@ -1,6 +1,6 @@
 #include "common/common_pch.h"
 
-#if defined(HAVE_QTDBUS)
+#if defined(__linux__)
 
 #include <QDBusConnection>
 #include <QDBusInterface>
