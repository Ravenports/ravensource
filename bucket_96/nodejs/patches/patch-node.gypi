--- node.gypi.orig	2026-06-01 07:22:41 UTC
+++ node.gypi
@@ -313,6 +313,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
