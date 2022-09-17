--- src/file.h.orig	2022-09-13 18:35:30 UTC
+++ src/file.h
@@ -90,6 +90,7 @@
 #include <stdarg.h>
 #include <locale.h>
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
