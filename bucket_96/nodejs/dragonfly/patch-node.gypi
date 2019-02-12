Remove this patch when dragonfly sysroot based on Release 5.4.2 or later

--- node.gypi.orig	2019-02-12 14:33:00 UTC
+++ node.gypi
@@ -306,7 +306,7 @@
     [ 'OS=="sunos"', {
       'ldflags': [ '-Wl,-M,/usr/lib/ld/map.noexstk' ],
     }],
-    [ 'OS in "freebsd linux"', {
+    [ 'OS in "linux"', {
       'ldflags': [ '-Wl,-z,relro',
                    '-Wl,-z,now' ]
     }],
