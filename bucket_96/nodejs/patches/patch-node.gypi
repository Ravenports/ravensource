--- node.gypi.orig	2024-05-15 12:35:06 UTC
+++ node.gypi
@@ -274,6 +274,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
