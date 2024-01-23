--- node.gypi.orig	2024-01-14 13:42:11 UTC
+++ node.gypi
@@ -270,6 +270,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
