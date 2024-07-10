--- node.gypi.orig	2024-07-08 12:39:59 UTC
+++ node.gypi
@@ -278,6 +278,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
