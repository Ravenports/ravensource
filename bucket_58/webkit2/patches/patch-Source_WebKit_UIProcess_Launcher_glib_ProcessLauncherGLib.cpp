--- Source/WebKit/UIProcess/Launcher/glib/ProcessLauncherGLib.cpp.orig	2024-08-13 05:20:01 UTC
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
@@ -53,7 +60,7 @@
 
 namespace WebKit {
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
 static bool isFlatpakSpawnUsable()
 {
     static std::optional<bool> ret;
@@ -150,7 +157,7 @@ void ProcessLauncher::launchProcess()
     }
 #endif
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     IPC::SocketPair pidSocketPair = IPC::createPlatformConnection(IPC::PlatformConnectionOptions::SetCloexecOnClient | IPC::PlatformConnectionOptions::SetCloexecOnServer | IPC::PlatformConnectionOptions::SetPasscredOnServer);
     GUniquePtr<gchar> pidSocket(g_strdup_printf("%d", pidSocketPair.client));
 #endif
@@ -202,7 +209,9 @@ void ProcessLauncher::launchProcess()
     argv[i++] = const_cast<char*>(realExecutablePath.data());
     argv[i++] = processIdentifier.get();
     argv[i++] = webkitSocket.get();
+#if TREAT_AS_LINUX
     argv[i++] = pidSocket.get();
+#endif
 #if ENABLE(DEVELOPER_MODE)
     if (configureJSCForTesting)
         argv[i++] = const_cast<char*>("--configure-jsc-for-testing");
@@ -220,14 +229,14 @@ void ProcessLauncher::launchProcess()
     // Please keep this comment in sync with the duplicate comment in XDGDBusProxy::launch.
     GRefPtr<GSubprocessLauncher> launcher = adoptGRef(g_subprocess_launcher_new(G_SUBPROCESS_FLAGS_INHERIT_FDS));
     g_subprocess_launcher_take_fd(launcher.get(), webkitSocketPair.client, webkitSocketPair.client);
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     g_subprocess_launcher_take_fd(launcher.get(), pidSocketPair.client, pidSocketPair.client);
 #endif
 
     GUniqueOutPtr<GError> error;
     GRefPtr<GSubprocess> process;
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     bool sandboxEnabled = isSandboxEnabled(m_launchOptions);
 
     if (sandboxEnabled && isFlatpakSpawnUsable())
@@ -239,13 +248,13 @@ void ProcessLauncher::launchProcess()
         process = bubblewrapSpawn(launcher.get(), m_launchOptions, argv, &error.outPtr());
 #endif // ENABLE(BUBBLEWRAP_SANDBOX)
     else
-#endif // OS(LINUX)
+#endif // TREAT_AS_LINUX 
         process = adoptGRef(g_subprocess_launcher_spawnv(launcher.get(), argv, &error.outPtr()));
 
     if (!process.get())
         g_error("Unable to spawn a new child process: %s", error->message);
 
-#if OS(LINUX)
+#if TREAT_AS_LINUX
     m_processID = IPC::readPIDFromPeer(pidSocketPair.server);
     RELEASE_ASSERT(!close(pidSocketPair.server));
 #else
