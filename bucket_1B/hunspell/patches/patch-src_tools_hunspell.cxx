--- src/tools/hunspell.cxx.orig	2026-10-04 18:42:59 UTC
+++ src/tools/hunspell.cxx
@@ -126,9 +126,9 @@
   DATADIR "/hunspell:"        \
   DATADIR "/myspell:"         \
   DATADIR "/myspell/dicts:"   \
-  "/usr/share/hunspell:"      \
-  "/usr/share/myspell:"       \
-  "/usr/share/myspell/dicts:" \
+  "%%PREFIX%%/share/hunspell:"      \
+  "%%PREFIX%%/share/myspell:"       \
+  "%%PREFIX%%/share/myspell/dicts:" \
   "/Library/Spelling"
 #define USEROOODIR {                       \
   ".openoffice.org/3/user/wordbook",       \
@@ -137,18 +137,12 @@
   ".config/libreoffice/4/user/wordbook",   \
   "Library/Spelling" }
 #define OOODIR                                       \
-  "/opt/openoffice.org/basis3.0/share/dict/ooo:"     \
-  "/usr/lib/openoffice.org/basis3.0/share/dict/ooo:" \
-  "/opt/openoffice.org2.4/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.4/share/dict/ooo:"       \
-  "/opt/openoffice.org2.3/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.3/share/dict/ooo:"       \
-  "/opt/openoffice.org2.2/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.2/share/dict/ooo:"       \
-  "/opt/openoffice.org2.1/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.1/share/dict/ooo:"       \
-  "/opt/openoffice.org2.0/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.0/share/dict/ooo"
+  "%%PREFIX%%/openoffice.org/basis3.0/share/dict/ooo:"     \
+  "%%PREFIX%%/openoffice.org2.4/share/dict/ooo:"           \
+  "%%PREFIX%%/openoffice.org2.3/share/dict/ooo:"           \
+  "%%PREFIX%%/openoffice.org2.2/share/dict/ooo:"           \
+  "%%PREFIX%%/openoffice.org2.1/share/dict/ooo:"           \
+  "%%PREFIX%%/openoffice.org2.0/share/dict/ooo"
 #define HOME getenv("HOME")
 #define LODIR                                       \
   "/opt/libreoffice/share/extensions:"              \
@@ -714,6 +708,12 @@ char* mymkdtemp(char *templ) {
     return NULL;
   }
   return odftmpdir;
+#elif defined __sun__
+  char *tmplt;
+  tmplt = mktemp(templ);
+  if (tmplt == NULL)
+      return NULL;
+  return (mkdir (tmplt, 0700) == 0) ? tmplt : NULL;
 #else
   return mkdtemp(templ);
 #endif
