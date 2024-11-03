--- spa/include/spa/utils/string.h.orig	2024-10-23 07:44:10 UTC
+++ spa/include/spa/utils/string.h
@@ -17,6 +17,11 @@ extern "C" {
 
 #include <spa/utils/defs.h>
 
+#if defined(__NetBSD__)
+// uselocale is not supported
+#define __LOCALE_C_ONLY
+#endif
+
 /**
  * \defgroup spa_string String handling
  * String handling utilities
