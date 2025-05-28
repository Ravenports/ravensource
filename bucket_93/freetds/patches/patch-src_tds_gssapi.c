--- src/tds/gssapi.c.orig	2025-03-06 20:38:39 UTC
+++ src/tds/gssapi.c
@@ -71,6 +71,10 @@
 #include <freetds/utils/string.h>
 #include <freetds/replacements.h>
 
+#if !defined(AI_V4MAPPED)
+#define AI_V4MAPPED    0
+#endif
+
 /**
  * \ingroup libtds
  * \defgroup auth Authentication
