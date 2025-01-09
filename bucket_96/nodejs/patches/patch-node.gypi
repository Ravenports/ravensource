--- node.gypi.orig	2025-01-07 13:00:24 UTC
+++ node.gypi
@@ -290,6 +290,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
