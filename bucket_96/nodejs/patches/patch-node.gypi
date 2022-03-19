--- node.gypi.orig	2022-03-09 15:59:54 UTC
+++ node.gypi
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
