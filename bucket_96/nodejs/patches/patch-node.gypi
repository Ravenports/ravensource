--- node.gypi.orig	2023-12-19 00:27:02 UTC
+++ node.gypi
@@ -270,6 +270,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
