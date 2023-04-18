--- node.gypi.orig	2023-04-10 19:58:53 UTC
+++ node.gypi
@@ -269,6 +269,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
