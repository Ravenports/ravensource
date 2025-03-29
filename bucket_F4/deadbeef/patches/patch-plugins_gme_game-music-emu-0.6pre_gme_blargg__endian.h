--- plugins/gme/game-music-emu-0.6pre/gme/blargg_endian.h.orig	2025-03-26 17:38:20 UTC
+++ plugins/gme/game-music-emu-0.6pre/gme/blargg_endian.h
@@ -23,7 +23,11 @@
 #if !defined (BLARGG_BIG_ENDIAN) && !defined (BLARGG_LITTLE_ENDIAN)
 #if defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && defined(__BIG_ENDIAN)
 	// GCC handles this for us
+#if defined (__DragonFly__)
+	#include <sys/endian.h>
+#else
 	#include <endian.h>
+#endif
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BLARGG_LITTLE_ENDIAN 1
 	#elif __BYTE_ORDER == __BIG_ENDIAN
@@ -34,9 +38,7 @@
 #if defined (LSB_FIRST) || defined (__LITTLE_ENDIAN__) || BLARGG_CPU_X86 || \
 		(defined (LITTLE_ENDIAN) && LITTLE_ENDIAN+0 != 1234)
 	#define BLARGG_LITTLE_ENDIAN 1
-#endif
-
-#if defined (MSB_FIRST)     || defined (__BIG_ENDIAN__) || defined (WORDS_BIGENDIAN) || \
+#elif defined (MSB_FIRST)     || defined (__BIG_ENDIAN__) || defined (WORDS_BIGENDIAN) || \
 	defined (__sparc__)     ||  BLARGG_CPU_POWERPC || \
 	(defined (BIG_ENDIAN) && BIG_ENDIAN+0 != 4321)
 	#define BLARGG_BIG_ENDIAN 1
