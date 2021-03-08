--- src/pty.cc.orig	2021-02-16 15:35:49 UTC
+++ src/pty.cc
@@ -78,6 +78,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -350,6 +354,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -358,6 +363,7 @@ fd_set_cpkt(vte::libc::FD& fd)
         int one = 1;
         return ioctl(fd.get(), TIOCPKT, &one);
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -392,6 +398,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -399,6 +406,7 @@ fd_setup(vte::libc::FD& fd)
                                  "ioctl(TIOCPKT)", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -458,6 +466,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -465,6 +474,7 @@ _vte_pty_open_posix(void)
                                  "ioctl(TIOCPKT)", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
