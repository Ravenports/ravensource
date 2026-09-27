--- node.gypi.orig	2026-09-16 09:28:32 UTC
+++ node.gypi
@@ -322,6 +322,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
