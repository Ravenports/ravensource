--- node.gypi.orig	2025-06-24 19:38:46 UTC
+++ node.gypi
@@ -296,6 +296,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
