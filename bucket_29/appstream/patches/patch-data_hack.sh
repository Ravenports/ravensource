--- data/hack.sh.orig	2026-11-01 14:26:11 UTC
+++ data/hack.sh
@@ -1,4 +1,4 @@
-#/bin/sh
+#!/bin/sh
 # Nasty hack for appstreamcli bug using relative paths
 echo ===  appstreamcli hack here  ===
 /bin/cat "$1" | "$2" news-to-metainfo --limit=6 "$3" - > "$4"
