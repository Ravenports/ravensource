--- common/unicode/platform.h.orig	2025-03-13 18:31:23 UTC
+++ common/unicode/platform.h
@@ -182,6 +182,9 @@
 #       include <sys/endian.h>
 #   endif
 #   define U_PLATFORM U_PF_BSD
+#elif defined(__DragonFly__)
+# include <sys/endian.h>
+# define U_PLATFORM U_PF_BSD
 #elif defined(sun) || defined(__sun)
     /* Check defined(__SVR4) || defined(__svr4__) to distinguish Solaris from SunOS? */
 #   define U_PLATFORM U_PF_SOLARIS
@@ -346,8 +349,8 @@
  */
 #ifdef U_IS_BIG_ENDIAN
     /* Use the predefined value. */
-#elif defined(BYTE_ORDER) && defined(BIG_ENDIAN)
-#   define U_IS_BIG_ENDIAN (BYTE_ORDER == BIG_ENDIAN)
+#elif defined(_BYTE_ORDER) && defined(_BIG_ENDIAN)
+#   define U_IS_BIG_ENDIAN (_BYTE_ORDER == _BIG_ENDIAN)
 #elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__)
     /* gcc */
 #   define U_IS_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
