--- src/pty.cc.orig	2020-05-13 09:51:07 UTC
+++ src/pty.cc
@@ -612,6 +612,7 @@ fd_set_cpkt(int fd)
 static int
 fd_setup(int fd)
 {
+#ifndef __sun__
         if (grantpt(fd) != 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY, "%s failed: %m\n", "grantpt");
@@ -644,6 +645,7 @@ fd_setup(int fd)
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -701,12 +703,14 @@ _vte_pty_open_posix(void)
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
 
         if (grantpt(fd) != 0) {
                 vte::util::restore_errno errsv;
