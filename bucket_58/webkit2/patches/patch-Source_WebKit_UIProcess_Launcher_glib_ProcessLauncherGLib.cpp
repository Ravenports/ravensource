--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2026-04-13 08:58:17 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -44,6 +44,13 @@
 #include <wtf/text/CString.h>
 #include <wtf/text/WTFString.h>
 
+#if defined __DragonFly__ || defined __FreeBSD__ || defined __NetBSD__ || defined __sun
+#  define TREAT_AS_LINUX 0
+#  define RUNNING_ON_VALGRIND 0
+#else
+#  define TREAT_AS_LINUX 1
+#endif
+
 #if USE(LIBWPE)
 #include "ProcessProviderLibWPE.h"
 #endif
@@ -56,7 +63,7 @@
 
 namespace WebKit {
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
 static bool isFlatpakSpawnUsable()
 {
     ASSERT(isInsideFlatpak());
@@ -215,7 +222,7 @@ void ProcessLauncher::launchProcess()
     GUniqueOutPtr<GError> error;
     GRefPtr<GSubprocess> process;
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     bool sandboxEnabled = m_launchOptions.extraInitializationData.get<HashTranslatorASCIILiteral>("enable-sandbox"_s) == "true"_s;
 
     if (sandboxEnabled && isInsideFlatpak() && isFlatpakSpawnUsable())
@@ -233,7 +240,7 @@ void ProcessLauncher::launchProcess()
     if (!process.get())
         g_error("Unable to spawn a new child process: %s", error->message);
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     if (isInsideFlatpak() || (sandboxEnabled && shouldUseBubblewrap())) {
         GRefPtr<GSocket> socket = adoptGRef(g_socket_new_from_fd(webkitSocketPair.server.release(), &error.outPtr()));
         if (!socket) {
