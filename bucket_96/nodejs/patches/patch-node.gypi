--- node.gypi.orig	2022-10-13 18:14:09 UTC
+++ node.gypi
@@ -258,6 +258,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
