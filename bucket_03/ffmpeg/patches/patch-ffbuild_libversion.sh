--- ffbuild/libversion.sh.orig	2018-11-01 18:34:22 UTC
+++ ffbuild/libversion.sh
@@ -1,3 +1,5 @@
+#!/bin/sh
+
 toupper(){
     echo "$@" | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
 }
