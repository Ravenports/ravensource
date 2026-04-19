--- debugger/src/debug.c.orig	2025-06-10 16:19:20 UTC
+++ debugger/src/debug.c
@@ -48,6 +48,12 @@ int grantpt(int fd);
 #elif defined(HAVE_PTY_H)
 #include <pty.h>
 #endif
+#if defined(__sun)
+#include <fcntl.h>
+#include <stropts.h>
+#include <sys/types.h>
+#include <sys/conf.h>
+#endif
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 #include <vte/vte.h>
@@ -1043,11 +1049,25 @@ void debug_init(void)
 	/* create debug terminal page */
 	terminal = vte_terminal_new();
 	/* create PTY */
+#ifdef __sun
+	pty_master = posix_openpt(O_RDWR | O_NOCTTY);
+	if (pty_master != -1) {
+		if (grantpt(pty_master) == 0 && unlockpt(pty_master) == 0) {
+			char *name = ptsname(pty_master);
+			pty_slave = open(name, O_RDWR | O_NOCTTY);
+			if (pty_slave != -1) {
+				ioctl(pty_slave, I_PUSH, "ptem");
+				ioctl(pty_slave, I_PUSH, "ldterm");
+			}
+		}
+	}
+#else
 	openpty(&pty_master, &pty_slave, NULL,
 		    NULL,
 		    NULL);
 	grantpt(pty_master);
 	unlockpt(pty_master);
+#endif
 #if GTK_CHECK_VERSION(3, 0, 0)
 	pty = vte_pty_new_foreign_sync(pty_master, NULL, NULL);
 	vte_terminal_set_pty(VTE_TERMINAL(terminal), pty);
