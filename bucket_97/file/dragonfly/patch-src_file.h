--- src/file.h.orig	2019-05-07 02:27:11 UTC
+++ src/file.h
@@ -520,6 +520,7 @@ protected int buffer_fill(const struct b
 
 #include <locale.h>
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
