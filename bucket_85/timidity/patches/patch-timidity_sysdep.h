--- timidity/sysdep.h.orig	2008-05-21 13:01:44 UTC
+++ timidity/sysdep.h
@@ -175,20 +175,9 @@ typedef unsigned long  u_ptr_size_t;
 #ifdef LITTLE_ENDIAN
 # define LE_SHORT(x) (x)
 # define LE_LONG(x) (x)
-# ifdef __FreeBSD__
-#  include <osreldate.h>
-#  if __FreeBSD_version <= 500000
-#    define BE_SHORT(x) __byte_swap_word(x)
-#    define BE_LONG(x) __byte_swap_long(x)
-#  else
-#    if __FreeBSD_version <= 500028
-#      define BE_SHORT(x) __uint8_swap_uint16(x)
-#      define BE_LONG(x) __uint8_swap_uint32(x)
-#    else
-#      define BE_SHORT(x) __bswap16(x)
-#      define BE_LONG(x) __bswap32(x)
-#    endif
-#  endif
+# if defined __FreeBSD__ || defined __DragonFly__
+#  define BE_SHORT(x) __bswap16(x)
+#  define BE_LONG(x) __bswap32(x)
 # else
 #  define BE_SHORT(x) XCHG_SHORT(x)
 #  define BE_LONG(x) XCHG_LONG(x)
