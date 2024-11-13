--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-10-21 09:00:02 UTC
+++ Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp
@@ -43,6 +43,13 @@
 #include <wtf/text/CString.h>
 #include <wtf/text/WTFString.h>
 
+#if defined __DragonFly__ || defined __FreeBSD__ || defined __NetBSD__
+#  define TREAT_AS_LINUX 0
+#  define RUNNING_ON_VALGRIND 0
+#else
+#  define TREAT_AS_LINUX 1
+#endif
+
 #if USE(LIBWPE)
 #include "ProcessProviderLibWPE.h"
 #endif
@@ -57,7 +64,7 @@ namespace WebKit {
 
 void ProcessLauncher::platformDestroy()
 {
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     if (m_pidServerSocket != -1) {
         close(m_pidServerSocket);
         m_pidServerSocket = -1;
@@ -65,7 +72,7 @@ void ProcessLauncher::platformDestroy()
 #endif
 }
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
 static bool isFlatpakSpawnUsable()
 {
     ASSERT(isInsideFlatpak());
@@ -135,7 +142,7 @@ void ProcessLauncher::launchProcess()
     }
 #endif
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     IPC::SocketPair pidSocketPair = IPC::createPlatformConnection(IPC::PlatformConnectionOptions::SetCloexecOnClient | IPC::PlatformConnectionOptions::SetCloexecOnServer | IPC::PlatformConnectionOptions::SetPasscredOnServer);
     GUniquePtr<gchar> pidSocketString(g_strdup_printf("%d", pidSocketPair.client));
 #endif
@@ -187,7 +194,9 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
+#if TREAT_AS_LINUX
     argv[i++] = pidSocketString.get();
+#endif
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
@@ -205,7 +214,7 @@ void ProcessLauncher::launchProcess()
     // Please keep this comment in sync with the duplicate comment in XDGDBusProxy::launch.
     GRefPtr<GSubprocessLauncher> launcher = adoptGRef(g_subprocess_launcher_new(G_SUBPROCESS_FLAGS_INHERIT_FDS));
     g_subprocess_launcher_take_fd(launcher.get(), webkitSocketPair.client, webkitSocketPair.client);
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     g_subprocess_launcher_take_fd(launcher.get(), pidSocketPair.client, pidSocketPair.client);
 #endif
 
@@ -226,7 +235,7 @@ void ProcessLauncher::launchProcess()
     GUniqueOutPtr<GError> error;
     GRefPtr<GSubprocess> process;
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     bool sandboxEnabled = m_launchOptions.extraInitializationData.get<HashTranslatorASCIILiteral>("enable-sandbox"_s) == "true"_s;
 
     if (sandboxEnabled && isInsideFlatpak() && isFlatpakSpawnUsable())
@@ -244,7 +253,7 @@ void ProcessLauncher::launchProcess()
     if (!process.get())
         g_error("Unable to spawn a new child process: %s", error->message);
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     GRefPtr<GSocket> pidSocket = adoptGRef(g_socket_new_from_fd(pidSocketPair.server, &error.outPtr()));
     if (!pidSocket)
         g_error("Failed to create pid socket wrapper: %s", error->message);
