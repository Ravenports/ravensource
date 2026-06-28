--- node.gypi.orig	2026-06-17 18:06:15 UTC
+++ node.gypi
@@ -313,6 +313,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
