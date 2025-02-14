--- node.gypi.orig	2025-01-30 10:37:59 UTC
+++ node.gypi
@@ -290,6 +290,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
