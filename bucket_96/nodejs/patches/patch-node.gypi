--- node.gypi.orig	2024-07-17 13:00:47 UTC
+++ node.gypi
@@ -278,6 +278,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
