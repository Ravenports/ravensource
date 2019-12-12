Use correct includes on SunOS.
Don't use packet mode on SunOS.

--- src/pty.cc.orig	2019-11-22 21:36:35 UTC
+++ src/pty.cc
@@ -64,12 +64,20 @@
 #if defined(__sun) && defined(HAVE_STROPTS_H)
 #include <stropts.h>
 #endif
+#if defined(__sun__)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
+#endif
 #include <glib.h>
 #include <gio/gio.h>
 #include "debug.h"
 
 #include <glib/gi18n-lib.h>
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 /* NSIG isn't in POSIX, so if it doesn't exist use this here. See bug #759196 */
 #ifndef NSIG
 #define NSIG (8 * sizeof(sigset_t))
@@ -622,6 +630,7 @@ fd_set_cpkt(int fd)
 static int
 fd_setup(int fd)
 {
+#ifndef __sun__
         if (fd_set_cloexec(fd) < 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -642,6 +651,7 @@ fd_setup(int fd)
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -699,12 +709,14 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
 	_vte_debug_print(VTE_DEBUG_PTY, "Allocated pty on fd %d.\n", (int)fd);
 
