--- node.gypi.orig	2026-01-19 10:31:56 UTC
+++ node.gypi
@@ -301,6 +301,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
