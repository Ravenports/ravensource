--- lib/snappy-fef67ac/compat.h.orig	2025-05-13 13:25:44 UTC
+++ lib/snappy-fef67ac/compat.h
@@ -4,6 +4,8 @@
 
 #ifdef __FreeBSD__
 #  include <sys/endian.h>
+#elif defined __DragonFly__ || defined __NetBSD__
+#  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || defined(__MACH__)  /* MacOS/X support */
 #  include <machine/endian.h>
 
