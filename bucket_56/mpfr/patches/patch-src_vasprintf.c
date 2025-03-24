--- src/vasprintf.c.orig	2025-02-01 23:44:50 UTC
+++ src/vasprintf.c
@@ -71,6 +71,7 @@ If not, see <https://www.gnu.org/license
 #endif /* HAVE_VA_COPY */
 
 #ifdef HAVE_WCHAR_H
+#include <stddef.h>
 #include <wchar.h>
 #endif
 
