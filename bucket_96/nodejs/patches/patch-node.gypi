--- node.gypi.orig	2023-01-24 16:08:39 UTC
+++ node.gypi
@@ -269,6 +269,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
