--- node.gypi.orig	2022-01-10 16:28:38 UTC
+++ node.gypi
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
