--- spa/include/spa/utils/string.h.orig	2025-06-27 11:16:18 UTC
+++ spa/include/spa/utils/string.h
@@ -25,6 +25,11 @@ extern "C" {
  #endif
 #endif
 
+#if defined(__NetBSD__)
+// uselocale is not supported
+#define __LOCALE_C_ONLY
+#endif
+
 /**
  * \defgroup spa_string String handling
  * String handling utilities
