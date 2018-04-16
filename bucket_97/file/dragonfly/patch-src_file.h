--- src/file.h.orig	2017-08-28 13:39:18 UTC
+++ src/file.h
@@ -501,6 +501,7 @@ protected int file_os2_apptype(struct ma
 #include <locale.h>
 #endif
 #if defined(HAVE_XLOCALE_H)
+#include <wchar.h>
 #include <xlocale.h>
 #endif
 
