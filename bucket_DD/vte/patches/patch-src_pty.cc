--- src/pty.cc.orig	2021-04-16 17:22:42 UTC
+++ src/pty.cc
@@ -77,6 +77,10 @@
 
 #include "missing.hh"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 namespace vte::base {
 
 Pty*
@@ -349,6 +353,7 @@ Pty::get_size(int* rows,
         return false;
 }
 
+#ifndef __sun__
 static int
 fd_set_cpkt(vte::libc::FD& fd)
 {
@@ -365,6 +370,7 @@ fd_set_cpkt(vte::libc::FD& fd)
 #endif
         return ret;
 }
+#endif
 
 static int
 fd_setup(vte::libc::FD& fd)
@@ -399,6 +405,7 @@ fd_setup(vte::libc::FD& fd)
                 return -1;
         }
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -406,6 +413,7 @@ fd_setup(vte::libc::FD& fd)
                                  "Setting packet mode", g_strerror(errsv));
                 return -1;
         }
+#endif
 
         return 0;
 }
@@ -465,6 +473,7 @@ _vte_pty_open_posix(void)
         }
 #endif /* !linux */
 
+#ifndef __sun__
         if (fd_set_cpkt(fd) < 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
                 _vte_debug_print(VTE_DEBUG_PTY,
@@ -472,6 +481,7 @@ _vte_pty_open_posix(void)
                                  "Setting packet mode", g_strerror(errsv));
                 return {};
         }
+#endif
 
         if (grantpt(fd.get()) != 0) {
                 auto errsv = vte::libc::ErrnoSaver{};
