--- utils/irssi-version.sh.orig	2023-10-01 13:46:33 UTC
+++ utils/irssi-version.sh
@@ -1,5 +1,7 @@
 #!/bin/sh
 
+cat ../irssi-version.h
+exit 0
 DATE=`grep '^v' $1/NEWS | head -1`
 VERSION_DATE=`echo "$DATE" | cut -f 2 -d ' ' | tr -d -`
 case $VERSION_DATE in
