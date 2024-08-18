--- node.gypi.orig	2024-07-19 02:41:03 UTC
+++ node.gypi
@@ -278,6 +278,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
