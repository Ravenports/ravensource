--- node.gypi.orig	2024-11-20 14:52:47 UTC
+++ node.gypi
@@ -274,6 +274,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
