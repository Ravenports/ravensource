--- node.gypi.orig	2026-11-11 00:20:19 UTC
+++ node.gypi
@@ -322,6 +322,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
