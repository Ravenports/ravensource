--- node.gypi.orig	2021-11-30 13:56:37 UTC
+++ node.gypi
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
