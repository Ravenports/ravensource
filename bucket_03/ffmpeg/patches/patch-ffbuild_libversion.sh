--- ffbuild/libversion.sh.orig	2018-02-12 00:29:04 UTC
+++ ffbuild/libversion.sh
@@ -1,3 +1,5 @@
+#!/bin/sh
+
 toupper(){
     echo "$@" | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
 }
