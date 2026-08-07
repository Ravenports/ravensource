--- node.gypi.orig	2026-08-03 08:15:52 UTC
+++ node.gypi
@@ -313,6 +313,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
