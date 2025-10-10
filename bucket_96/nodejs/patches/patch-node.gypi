--- node.gypi.orig	2025-09-25 14:43:15 UTC
+++ node.gypi
@@ -299,6 +299,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
