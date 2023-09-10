--- node.gypi.orig	2023-09-07 12:46:29 UTC
+++ node.gypi
@@ -269,6 +269,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
