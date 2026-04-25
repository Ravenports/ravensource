--- node.gypi.orig	2026-04-01 02:23:55 UTC
+++ node.gypi
@@ -306,6 +306,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
