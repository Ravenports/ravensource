--- src/tools/hunspell.cxx.orig	2026-10-31 23:19:46 UTC
+++ src/tools/hunspell.cxx
@@ -115,9 +115,9 @@
   HUNSPELL_DATADIR "/hunspell:"        \
   HUNSPELL_DATADIR "/myspell:"         \
   HUNSPELL_DATADIR "/myspell/dicts:"   \
-  "/usr/share/hunspell:"      \
-  "/usr/share/myspell:"       \
-  "/usr/share/myspell/dicts"
+  "%%PREFIX%%/share/hunspell:"      \
+  "%%PREFIX%%/share/myspell:"       \
+  "%%PREFIX%%/share/myspell/dicts"
 #define HOME getenv("HOME")
 #define LODIR                                       \
   "/opt/libreoffice/share/extensions:"              \
