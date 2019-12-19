--- src/file.h.orig	2019-06-26 20:31:31 UTC
+++ src/file.h
@@ -521,6 +521,7 @@ protected int buffer_fill(const struct b
 
 #include <locale.h>
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
