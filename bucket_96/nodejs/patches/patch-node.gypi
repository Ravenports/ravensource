--- node.gypi.orig	2022-06-16 12:18:03 UTC
+++ node.gypi
@@ -258,6 +258,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
