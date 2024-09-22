--- common.gypi.orig	2024-09-17 19:34:56 UTC
+++ common.gypi
@@ -483,17 +483,17 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris aix os400"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix os400 cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
           '-fno-exceptions',
           '-fno-strict-aliasing',
-          '-std=gnu++17',
+          '-std=gnu++20',
         ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
         'ldflags': [ '-rdynamic' ],
