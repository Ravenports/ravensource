--- ffbuild/libversion.sh.orig	2019-02-09 20:56:02 UTC
+++ ffbuild/libversion.sh
@@ -1,3 +1,5 @@
+#!/bin/sh
+
 toupper(){
     echo "$@" | tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
 }
