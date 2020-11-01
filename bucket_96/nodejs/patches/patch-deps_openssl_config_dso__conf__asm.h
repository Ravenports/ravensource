--- deps/openssl/config/dso_conf_asm.h.orig	2020-10-21 19:22:29 UTC
+++ deps/openssl/config/dso_conf_asm.h
@@ -25,7 +25,7 @@
 # include "./archs/VC-WIN64A/asm/crypto/include/internal/dso_conf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/asm/crypto/include/internal/dso_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/crypto/include/internal/dso_conf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/asm/crypto/include/internal/dso_conf.h"
