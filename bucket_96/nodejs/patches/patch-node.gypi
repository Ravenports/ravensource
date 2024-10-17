--- node.gypi.orig	2024-10-16 03:45:05 UTC
+++ node.gypi
@@ -274,6 +274,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
