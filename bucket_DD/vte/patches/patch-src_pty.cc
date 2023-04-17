--- src/pty.cc.orig	2023-04-13 09:57:27 UTC
+++ src/pty.cc
@@ -72,6 +72,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -335,6 +339,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -351,6 +356,7 @@ fd_set_cpkt(vte::libc::FD& fd)
 #endif
         return ret;
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -385,6 +391,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -392,6 +399,7 @@ fd_setup(vte::libc::FD& fd)
                                  "Setting packet mode", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -461,6 +469,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -468,6 +477,7 @@ _vte_pty_open_posix(void)
                                  "Setting packet mode", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
