--- node.gypi.orig	2022-02-22 22:27:05 UTC
+++ node.gypi
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
