--- tbl2mim.awk.orig	2023-04-26 10:19:35 UTC
+++ tbl2mim.awk
@@ -1,4 +1,4 @@
-#!/usr/bin/gawk -f
+#!/usr/bin/awk
 # Copyright (C) 2006
 #   National Institute of Advanced Industrial Science and Technology (AIST)
 #   Registration Number H15PRO112
@@ -25,6 +25,7 @@ BEGIN {
     begin_table = 0;
 }
 
+/^ *###/ { next; }
 /^ICON *=/ { ICON = " \""$3"\""; next; }
 /^NAME *=/ { NAME = tolower($3); next; }
 /^LANGUAGES *=/ {
