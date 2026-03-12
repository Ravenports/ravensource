--- node.gypi.orig	2026-02-24 04:43:38 UTC
+++ node.gypi
@@ -306,6 +306,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
