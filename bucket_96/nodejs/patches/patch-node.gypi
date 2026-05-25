--- node.gypi.orig	2026-05-06 23:11:59.000000000 -0000
+++ node.gypi
@@ -313,6 +313,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
