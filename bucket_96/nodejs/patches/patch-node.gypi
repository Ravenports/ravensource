--- node.gypi.orig	2024-05-02 12:49:15 UTC
+++ node.gypi
@@ -270,6 +270,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
