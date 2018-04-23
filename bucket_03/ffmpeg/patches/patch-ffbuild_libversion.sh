--- ffbuild/libversion.sh.orig	2018-04-20 10:02:55 UTC
+++ ffbuild/libversion.sh
@@ -1,3 +1,5 @@
+#!/bin/sh
+
 toupper(){
     echo "$@" | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
 }
