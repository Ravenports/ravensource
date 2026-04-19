--- scope/src/conterm.c.orig	2025-06-10 16:19:20 UTC
+++ scope/src/conterm.c
@@ -42,6 +42,11 @@
 #elif defined(HAVE_PTY_H)
 #include <pty.h>
 #endif
+#if defined(__sun)
+#include <fcntl.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 int grantpt(int fd);
 int unlockpt(int fd);
 
@@ -522,10 +527,21 @@ void conterm_init(void)
 		pref_terminal_padding = FALSE;
 	}
 
+#ifdef __sun
+	pty_master = posix_openpt(O_RDWR | O_NOCTTY);
+	if (pty_master != -1 &&
+		grantpt(pty_master) == 0 && unlockpt(pty_master) == 0 &&
+		(pty_name = ptsname(pty_master)) != NULL &&
+		(pty_slave = open(pty_name, O_RDWR | O_NOCTTY)) != -1)
+	{
+		ioctl(pty_slave, I_PUSH, "ptem");
+		ioctl(pty_slave, I_PUSH, "ldterm");
+#else
 	if (openpty(&pty_master, &pty_slave, NULL, NULL, NULL) == 0 &&
 		grantpt(pty_master) == 0 && unlockpt(pty_master) == 0 &&
 		(pty_name = ttyname(pty_slave)) != NULL)
 	{
+#endif
 #if VTE_CHECK_VERSION(0, 25, 0)
 		GError *gerror = NULL;
 		VtePty *pty = vte_pty_new_foreign(pty_master, &gerror);
