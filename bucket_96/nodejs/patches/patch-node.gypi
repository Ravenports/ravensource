--- node.gypi.orig	2026-01-26 18:28:10 UTC
+++ node.gypi
@@ -301,6 +301,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
