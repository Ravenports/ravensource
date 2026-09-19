--- node.gypi.orig	2026-08-26 18:21:49 UTC
+++ node.gypi
@@ -319,6 +319,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
