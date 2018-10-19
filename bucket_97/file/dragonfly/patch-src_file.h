--- src/file.h.orig	2018-10-15 16:29:16 UTC
+++ src/file.h
@@ -518,6 +518,7 @@ protected int buffer_fill(const struct b
 
 #include <locale.h>
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
