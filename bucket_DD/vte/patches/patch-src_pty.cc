--- src/pty.cc.orig	2022-11-27 20:28:23 UTC
+++ src/pty.cc
@@ -72,6 +72,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -344,6 +348,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -360,6 +365,7 @@ fd_set_cpkt(vte::libc::FD& fd)
 #endif
         return ret;
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -394,6 +400,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -401,6 +408,7 @@ fd_setup(vte::libc::FD& fd)
                                  "Setting packet mode", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -460,6 +468,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -467,6 +476,7 @@ _vte_pty_open_posix(void)
                                  "Setting packet mode", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
