Use correct includes on SunOS.
Don't use packet mode on SunOS.

--- src/vte.cc.orig	2019-11-22 21:36:35 UTC
+++ src/vte.cc
@@ -29,6 +29,10 @@
 #ifdef HAVE_SYS_TERMIOS_H
 #include <sys/termios.h>
 #endif
+#if defined(__sun__)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n-lib.h>
@@ -4094,6 +4098,9 @@ Terminal::pty_io_read(GIOChannel *channe
 			bp = chunk->data + chunk->len;
 			len = 0;
 			do {
+#ifdef __sun__
+				int ret = read (fd, bp, rem);
+#else
                                 /* We'd like to read (fd, bp, rem); but due to TIOCPKT mode
                                  * there's an extra input byte returned at the beginning.
                                  * We need to see what that byte is, but otherwise drop it
@@ -4104,6 +4111,7 @@ Terminal::pty_io_read(GIOChannel *channe
                                 int ret = read (fd, bp - 1, rem + 1);
                                 pkt_header = bp[-1];
                                 bp[-1] = save;
+#endif
 				switch (ret){
 					case -1:
 						err = errno;
@@ -4112,6 +4120,7 @@ Terminal::pty_io_read(GIOChannel *channe
 						eof = TRUE;
 						goto out;
 					default:
+#ifndef __sun__
                                                 ret--;
 
                                                 if (pkt_header & TIOCPKT_IOCTL) {
@@ -4132,6 +4141,7 @@ Terminal::pty_io_read(GIOChannel *channe
                                                 } else if (pkt_header & TIOCPKT_START) {
                                                         pty_scroll_lock_changed(false);
                                                 }
+#endif
 
 						bp += ret;
 						rem -= ret;
