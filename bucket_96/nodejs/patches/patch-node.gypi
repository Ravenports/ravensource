--- node.gypi.orig	2026-02-03 00:18:05 UTC
+++ node.gypi
@@ -301,6 +301,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
