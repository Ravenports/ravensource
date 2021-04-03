--- src/file.h.orig	2021-02-23 00:49:06 UTC
+++ src/file.h
@@ -561,6 +561,7 @@ protected int buffer_fill(const struct b
 
 #include <locale.h>
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
