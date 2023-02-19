--- common.gypi.orig	2023-02-16 16:14:34 UTC
+++ common.gypi
@@ -393,11 +393,11 @@
           'BUILDING_UV_SHARED=1',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris aix"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++17' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
