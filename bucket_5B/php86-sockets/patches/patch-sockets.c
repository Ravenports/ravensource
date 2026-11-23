OmniOS needs IFNAMSIZ definition in <net/if.h>

--- sockets.c.orig	2026-01-13 21:40:53 UTC
+++ sockets.c
@@ -51,9 +51,7 @@
 # include <sys/uio.h>
 # define set_errno(a) (errno = a)
 # include "php_sockets.h"
-# ifdef HAVE_IF_NAMETOINDEX
 #  include <net/if.h>
-# endif
 # if defined(HAVE_LINUX_SOCK_DIAG_H)
 #  include <linux/sock_diag.h>
 # else
