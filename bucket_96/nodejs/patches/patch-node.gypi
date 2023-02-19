--- node.gypi.orig	2023-02-16 16:14:46 UTC
+++ node.gypi
@@ -269,6 +269,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
