--- common.gypi.orig	2024-07-19 02:40:59 UTC
+++ common.gypi
@@ -482,13 +482,13 @@
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
-        'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++17' ],
+        'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++20' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
         'ldflags': [ '-rdynamic' ],
         'target_conditions': [
