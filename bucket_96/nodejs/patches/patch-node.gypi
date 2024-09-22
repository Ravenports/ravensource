--- node.gypi.orig	2024-09-17 19:35:01 UTC
+++ node.gypi
@@ -278,6 +278,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
