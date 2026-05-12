--- src/tools/hunspell.cxx.orig	2026-05-05 07:19:07 UTC
+++ src/tools/hunspell.cxx
@@ -119,9 +119,9 @@
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
 #define USEROOODIR {                  \
   ".openoffice.org/3/user/wordbook", \
@@ -129,18 +129,12 @@
   ".openoffice.org2.0/user/wordbook",\
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
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
@@ -663,6 +657,12 @@ char* mymkdtemp(char *templ) {
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
