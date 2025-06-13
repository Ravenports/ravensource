--- node.gypi.orig	2025-06-09 16:53:47 UTC
+++ node.gypi
@@ -296,6 +296,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
