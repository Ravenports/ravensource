--- src/pty.cc.orig	2025-06-05 06:21:19 UTC
+++ src/pty.cc
@@ -77,6 +77,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -340,6 +344,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -356,6 +361,7 @@ fd_set_cpkt(vte::libc::FD& fd)
 #endif
         return ret;
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -390,6 +396,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -397,6 +404,7 @@ fd_setup(vte::libc::FD& fd)
                                  "Setting packet mode", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -478,6 +486,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -485,6 +494,7 @@ _vte_pty_open_posix(void)
                                  "Setting packet mode", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
