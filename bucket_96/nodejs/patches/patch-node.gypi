--- node.gypi.orig	2026-10-07 07:39:49 UTC
+++ node.gypi
@@ -322,6 +322,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
