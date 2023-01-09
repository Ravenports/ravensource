--- node.gypi.orig	2022-12-14 11:28:44 UTC
+++ node.gypi
@@ -266,6 +266,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
