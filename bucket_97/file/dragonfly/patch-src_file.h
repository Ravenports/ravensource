--- src/file.h.orig	2018-05-24 18:09:17 UTC
+++ src/file.h
@@ -515,6 +515,7 @@ protected int buffer_fill(const struct b
 #include <locale.h>
 #endif
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
