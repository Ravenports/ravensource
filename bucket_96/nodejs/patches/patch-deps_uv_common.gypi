--- deps/uv/common.gypi.orig	2022-06-16 12:18:00 UTC
+++ deps/uv/common.gypi
@@ -135,7 +135,7 @@
           }]
         ]
       }],
-      ['OS in "freebsd dragonflybsd linux openbsd solaris android aix"', {
+      ['OS in "freebsd dragonflybsd linux openbsd netbsd solaris android aix"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'target_conditions': [
