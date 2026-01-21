--- node.gypi.orig	2026-01-12 17:56:20 UTC
+++ node.gypi
@@ -299,6 +299,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
