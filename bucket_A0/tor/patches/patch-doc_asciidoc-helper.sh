--- doc/asciidoc-helper.sh.orig	2026-10-07 14:40:59 UTC
+++ doc/asciidoc-helper.sh
@@ -12,11 +12,6 @@ if [ $# != 3 ]; then
     exit 1
 fi
 
-if [ -z "$SOURCE_DATE_EPOCH" ]; then
-    SOURCE_DATE_EPOCH="$(git -C "$(dirname "$0")" show --no-patch --format='%ct')"
-    export SOURCE_DATE_EPOCH
-fi
-
 output=$3
 
 if [ "$1" = "html" ]; then
