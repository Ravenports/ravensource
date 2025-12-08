--- node.gypi.orig	2025-11-16 23:17:52 UTC
+++ node.gypi
@@ -299,6 +299,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
