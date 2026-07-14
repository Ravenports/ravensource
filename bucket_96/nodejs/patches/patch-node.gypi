--- node.gypi.orig	2026-06-24 07:02:38 UTC
+++ node.gypi
@@ -313,6 +313,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
