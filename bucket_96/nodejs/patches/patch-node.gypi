--- node.gypi.orig	2025-08-14 20:34:26 UTC
+++ node.gypi
@@ -296,6 +296,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
