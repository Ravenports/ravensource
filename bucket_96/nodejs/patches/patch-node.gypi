--- node.gypi.orig	2023-07-20 18:27:41 UTC
+++ node.gypi
@@ -269,6 +269,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
