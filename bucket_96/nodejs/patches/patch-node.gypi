--- node.gypi.orig	2025-05-08 08:26:21 UTC
+++ node.gypi
@@ -296,6 +296,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
