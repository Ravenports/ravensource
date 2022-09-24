--- node.gypi.orig	2022-09-23 01:27:25 UTC
+++ node.gypi
@@ -258,6 +258,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
