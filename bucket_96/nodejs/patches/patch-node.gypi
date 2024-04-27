--- node.gypi.orig	2024-04-24 14:03:53 UTC
+++ node.gypi
@@ -270,6 +270,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
