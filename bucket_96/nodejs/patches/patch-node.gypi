--- node.gypi.orig	2026-02-09 23:10:33 UTC
+++ node.gypi
@@ -305,6 +305,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
