--- node.gypi.orig	2024-12-10 10:44:44 UTC
+++ node.gypi
@@ -290,6 +290,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
