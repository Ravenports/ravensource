--- common/unicode/platform.h.orig	2020-12-17 19:34:38 UTC
+++ common/unicode/platform.h
@@ -178,6 +178,9 @@
 #       include <sys/endian.h>
 #   endif
 #   define U_PLATFORM U_PF_BSD
+#elif defined(__DragonFly__)
+# include <sys/endian.h>
+# define U_PLATFORM U_PF_BSD
 #elif defined(sun) || defined(__sun)
     /* Check defined(__SVR4) || defined(__svr4__) to distinguish Solaris from SunOS? */
 #   define U_PLATFORM U_PF_SOLARIS
@@ -374,8 +377,8 @@
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
