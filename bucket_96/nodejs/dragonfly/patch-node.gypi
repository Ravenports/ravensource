Remove this patch when dragonfly sysroot based on Release 5.4.2 or later

--- node.gypi.orig	2019-06-27 10:12:19 UTC
+++ node.gypi
@@ -299,7 +299,7 @@
     [ 'OS=="sunos"', {
       'ldflags': [ '-Wl,-M,/usr/lib/ld/map.noexstk' ],
     }],
-    [ 'OS in "freebsd linux"', {
+    [ 'OS in "linux"', {
       'ldflags': [ '-Wl,-z,relro',
                    '-Wl,-z,now' ]
     }],
