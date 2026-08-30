--- node.gypi.orig	2026-08-25 23:43:41 UTC
+++ node.gypi
@@ -319,6 +319,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
