--- src/tools/hunspell.cxx.orig	2018-11-12 20:38:56 UTC
+++ src/tools/hunspell.cxx
@@ -116,9 +116,9 @@
 #include "../parsers/odfparser.hxx"
 
 #define LIBDIR                \
-  "/usr/share/hunspell:"      \
-  "/usr/share/myspell:"       \
-  "/usr/share/myspell/dicts:" \
+  "%%PREFIX%%/share/hunspell:"      \
+  "%%PREFIX%%/share/myspell:"       \
+  "%%PREFIX%%/share/myspell/dicts:" \
   "/Library/Spelling"
 #define USEROOODIR {                  \
   ".openoffice.org/3/user/wordbook", \
@@ -126,18 +126,12 @@
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
@@ -640,6 +634,12 @@ char* mymkdtemp(char *templ) {
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
