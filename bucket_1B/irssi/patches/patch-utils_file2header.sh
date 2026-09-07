--- utils/file2header.sh.orig	2023-10-01 13:46:33 UTC
+++ utils/file2header.sh
@@ -1,5 +1,5 @@
 #!/bin/sh
 
-echo "const char *$2 ="
-cat $1|sed 's/\\/\\\\/g'|sed 's/"/\\"/g'|sed 's/^/\"/'|sed 's/$/\\n\"/'
-echo ";"
+printf 'const char *%s =\n' "$2"
+perl -pe 's/([\\"])/\\$1/g; s/^/"/; s/$/\\n"/' "$1"
+printf ';\n'