--- src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h.orig	2024-04-29 14:34:19 UTC
+++ src/java.desktop/unix/native/libpipewire/include/spa/utils/string.h
@@ -17,6 +17,11 @@ extern "C" {
 
 #include <spa/utils/defs.h>
 
+#if defined(__NetBSD__)
+// uselocale is not supported on NetBSD
+#define __LOCALE_C_ONLY
+#endif
+
 /**
  * \defgroup spa_string String handling
  * String handling utilities
