--- ext/standard/proc_open.c.orig	2024-11-19 17:11:09 UTC
+++ ext/standard/proc_open.c
@@ -45,10 +45,10 @@
 #ifdef HAVE_OPENPTY
 # ifdef HAVE_PTY_H
 #  include <pty.h>
-# elif defined(__FreeBSD__)
+# elif defined(__FreeBSD__) && !defined(__MidnightBSD__)
 /* FreeBSD defines `openpty` in <libutil.h> */
 #  include <libutil.h>
-# elif defined(__NetBSD__) || defined(__DragonFly__)
+# elif defined(__NetBSD__) || defined(__DragonFly__) || defined(__MidnightBSD__)
 /* On recent NetBSD/DragonFlyBSD releases the emalloc, estrdup ... calls had been introduced in libutil */
 #  if defined(__NetBSD__)
 #    include <sys/termios.h>
