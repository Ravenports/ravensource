--- src/mkvtoolnix-gui/util/sleep_inhibitor/linux_logind.cpp.orig	2024-04-28 10:37:21 UTC
+++ src/mkvtoolnix-gui/util/sleep_inhibitor/linux_logind.cpp
@@ -1,6 +1,6 @@
 #include "common/common_pch.h"
 
-#if defined(HAVE_QTDBUS)
+#if defined(__linux__)
 
 #include <QDBusConnection>
 #include <QDBusInterface>
