--- node.gypi.orig	2022-11-29 18:29:52 UTC
+++ node.gypi
@@ -266,6 +266,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
