--- lib/crypto/builtin/aes/brg_endian.h.orig	2025-08-20 19:44:32 UTC
+++ lib/crypto/builtin/aes/brg_endian.h
@@ -35,6 +35,8 @@ Issue Date: 10/09/2018
 #  include <sys/isa_defs.h>
 #elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 #  include <sys/endian.h>
+#elif defined( __DragonFly__)
+#  include <sys/endian.h>
 #elif defined( BSD ) && ( BSD >= 199103 ) || defined( __APPLE__ ) || \
       defined( __CYGWIN32__ ) || defined( __DJGPP__ ) || defined( __osf__ )
 #  include <machine/endian.h>
