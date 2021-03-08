--- src/vte.cc.orig	2021-02-16 15:35:49 UTC
+++ src/vte.cc
@@ -29,6 +29,13 @@
 #ifdef HAVE_SYS_TERMIOS_H
 #include <sys/termios.h>
 #endif
+#ifdef HAVE_TERMIOS_H
+#include <termios.h>
+#endif
+#if defined(__sun__)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
+#endif
 
 #include <glib.h>
 #include <glib-unix.h>
@@ -3969,6 +3976,9 @@ Terminal::pty_io_read(int const fd,
 			bp = chunk->data + chunk->len;
 			len = 0;
 			do {
+#ifdef __sun__
+				int ret = read (fd, bp, rem);
+#else
                                 /* We'd like to read (fd, bp, rem); but due to TIOCPKT mode
                                  * there's an extra input byte returned at the beginning.
                                  * We need to see what that byte is, but otherwise drop it
@@ -3980,6 +3990,7 @@ Terminal::pty_io_read(int const fd,
                                 int ret = read (fd, bp - 1, rem + 1);
                                 pkt_header = bp[-1];
                                 bp[-1] = save;
+#endif
 				switch (ret){
 					case -1:
 						err = errno;
@@ -3989,11 +4000,13 @@ Terminal::pty_io_read(int const fd,
 						goto out;
 					default:
                                                 ret--;
-
+#ifndef __sun__
                                                 if (pkt_header == TIOCPKT_DATA) {
+#endif
                                                         bp += ret;
                                                         rem -= ret;
                                                         len += ret;
+#ifndef __sun__
                                                 } else {
                                                         if (pkt_header & TIOCPKT_IOCTL) {
                                                                 /* We'd like to always be informed when the termios change,
@@ -4015,6 +4028,7 @@ Terminal::pty_io_read(int const fd,
                                                                 pty_scroll_lock_changed(false);
                                                         }
                                                 }
+#endif
 						break;
 				}
 			} while (rem);
