--- node.gypi.orig	2025-02-13 11:53:54 UTC
+++ node.gypi
@@ -295,6 +295,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
