--- node.gypi.orig	2024-01-22 12:13:24 UTC
+++ node.gypi
@@ -270,6 +270,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
