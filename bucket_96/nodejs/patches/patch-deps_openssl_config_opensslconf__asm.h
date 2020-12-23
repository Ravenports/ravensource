--- deps/openssl/config/opensslconf_asm.h.orig	2020-12-22 17:41:56 UTC
+++ deps/openssl/config/opensslconf_asm.h
@@ -113,7 +113,7 @@
 # include "./archs/VC-WIN64A/asm/include/openssl/opensslconf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined (__DragonFly__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/asm/include/openssl/opensslconf.h"
