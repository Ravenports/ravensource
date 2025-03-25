--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2025-03-11 09:29:45 UTC
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
@@ -55,7 +62,7 @@
 
 namespace WebKit {
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
 static bool isFlatpakSpawnUsable()
 {
     ASSERT(isInsideFlatpak());
@@ -127,7 +134,7 @@ void ProcessLauncher::launchProcess()
     }
 #endif
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     IPC::SocketPair pidSocketPair = IPC::createPlatformConnection(IPC::PlatformConnectionOptions::SetCloexecOnClient | IPC::PlatformConnectionOptions::SetCloexecOnServer | IPC::PlatformConnectionOptions::SetPasscredOnServer);
     GUniquePtr<gchar> pidSocketString(g_strdup_printf("%d", pidSocketPair.client.value()));
 #endif
@@ -181,7 +188,7 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     argv[i++] = pidSocketString.get();
 #endif
 #if ENABLE(DEVELOPER_MODE)
@@ -204,7 +211,7 @@ void ProcessLauncher::launchProcess()
     GRefPtr<GSubprocessLauncher> launcher = adoptGRef(g_subprocess_launcher_new(G_SUBPROCESS_FLAGS_INHERIT_FDS));
     int webkitClientSocketValue = webkitSocketPair.client.release();
     g_subprocess_launcher_take_fd(launcher.get(), webkitClientSocketValue, webkitClientSocketValue);
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     int pidClientSocketValue = pidSocketPair.client.release();
     g_subprocess_launcher_take_fd(launcher.get(), pidClientSocketValue, pidClientSocketValue);
 #endif
@@ -226,7 +233,7 @@ void ProcessLauncher::launchProcess()
     GUniqueOutPtr<GError> error;
     GRefPtr<GSubprocess> process;
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     bool sandboxEnabled = m_launchOptions.extraInitializationData.get<HashTranslatorASCIILiteral>("enable-sandbox"_s) == "true"_s;
 
     if (sandboxEnabled && isInsideFlatpak() && isFlatpakSpawnUsable())
@@ -238,13 +245,13 @@ void ProcessLauncher::launchProcess()
         process = bubblewrapSpawn(launcher.get(), m_launchOptions, m_dbusProxy, argv, &error.outPtr());
 #endif // ENABLE(BUBBLEWRAP_SANDBOX)
     else
-#endif // OS(LINUX)
+#endif // TREAT_AS_LINUX
         process = adoptGRef(g_subprocess_launcher_spawnv(launcher.get(), argv, &error.outPtr()));
 
     if (!process.get())
         g_error("Unable to spawn a new child process: %s", error->message);
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     GRefPtr<GSocket> pidSocket = adoptGRef(g_socket_new_from_fd(pidSocketPair.server.release(), &error.outPtr()));
     if (!pidSocket)
         // Note: g_socket_new_from_fd() takes ownership of the fd only on success, so if this error
