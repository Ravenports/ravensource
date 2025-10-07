--- node.gypi.orig	2025-09-10 19:10:18 UTC
+++ node.gypi
@@ -299,6 +299,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
