--- deps/uv/common.gypi.orig	2024-09-17 19:34:58 UTC
+++ deps/uv/common.gypi
@@ -135,7 +135,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix os400"', {
+      ['OS in "freebsd dragonflybsd linux openbsd netbsd solaris android aix os400"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
