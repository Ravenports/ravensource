--- src/flexdef.h.orig	2026-11-10 13:01:56 UTC
+++ src/flexdef.h
@@ -99,6 +99,7 @@
 #include "gettext.h"
 #define _(String) gettext (String)
 #else
+#include "gettext.h"
 #define _(STRING) STRING
 #endif /* ENABLE_NLS */
 
