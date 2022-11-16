--- node.gypi.orig	2022-11-14 02:26:07 UTC
+++ node.gypi
@@ -258,6 +258,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
