--- common.gypi.orig	2024-11-20 14:52:38 UTC
+++ common.gypi
@@ -483,11 +483,11 @@
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
