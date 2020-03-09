--- src/pty.cc.orig	2020-03-03 07:51:17.000000000 +0100
+++ src/pty.cc	2020-03-09 14:10:18.905175000 +0100
@@ -619,6 +619,7 @@
 static int
 fd_setup(int fd)
 {
+#ifndef __sun__
         if (fd_set_cloexec(fd) < 0) {
                 vte::util::restore_errno errsv;
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -639,6 +640,7 @@
                                  "%s failed: %s", "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -696,12 +698,14 @@
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
 
