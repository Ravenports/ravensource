--- node.gypi.orig	2024-10-24 12:44:08 UTC
+++ node.gypi
@@ -274,6 +274,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
