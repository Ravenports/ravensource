--- src/pty.cc.orig	2025-10-11 20:43:24 UTC
+++ src/pty.cc
@@ -77,6 +77,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -345,6 +349,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -361,6 +366,7 @@ fd_set_cpkt(vte::libc::FD& fd)
 #endif
         return ret;
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -397,6 +403,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(vte::debug::category::PTY,
@@ -404,6 +411,7 @@ fd_setup(vte::libc::FD& fd)
                                  "Setting packet mode", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -485,6 +493,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(vte::debug::category::PTY,
@@ -492,6 +501,7 @@ _vte_pty_open_posix(void)
                                  "Setting packet mode", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
