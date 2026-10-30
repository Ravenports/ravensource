--- node.gypi.orig	2026-10-14 07:50:50 UTC
+++ node.gypi
@@ -322,6 +322,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
