--- Source/ThirdParty/aes-gladman/brg_endian.h.orig	2025-08-12 11:54:40 UTC
+++ Source/ThirdParty/aes-gladman/brg_endian.h
@@ -33,7 +33,7 @@ Issue Date: 10/09/2018
 /* Include files where endian defines and byteswap functions may reside */
 #if defined( __sun )
 #  include <sys/isa_defs.h>
-#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
+#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ ) || defined( __DragonFly__ )
 #  include <sys/endian.h>
 #elif defined( BSD ) && ( BSD >= 199103 ) || defined( __APPLE__ ) || \
       defined( __CYGWIN32__ ) || defined( __DJGPP__ ) || defined( __osf__ )
