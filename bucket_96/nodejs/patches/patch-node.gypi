--- node.gypi.orig	2025-07-15 17:11:20 UTC
+++ node.gypi
@@ -296,6 +296,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
