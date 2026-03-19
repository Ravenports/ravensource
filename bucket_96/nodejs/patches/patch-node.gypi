--- node.gypi.orig	2026-03-03 01:28:35 UTC
+++ node.gypi
@@ -306,6 +306,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
