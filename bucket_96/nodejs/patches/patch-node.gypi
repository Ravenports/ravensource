--- node.gypi.orig	2025-03-13 10:53:09 UTC
+++ node.gypi
@@ -299,6 +299,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
