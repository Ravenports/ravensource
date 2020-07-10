--- src/vasprintf.c.orig	2020-06-01 10:39:52 UTC
+++ src/vasprintf.c
@@ -72,6 +72,7 @@ https://www.gnu.org/licenses/ or write t
 #endif /* HAVE_VA_COPY */
 
 #ifdef HAVE_WCHAR_H
+#include <stddef.h>
 #include <wchar.h>
 #endif
 
