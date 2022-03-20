--- node.gypi.orig	2022-03-10 18:17:28 UTC
+++ node.gypi
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
