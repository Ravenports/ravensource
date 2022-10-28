--- node.gypi.orig	2022-10-17 20:23:27 UTC
+++ node.gypi
@@ -258,6 +258,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
