--- common.gypi.orig	2026-06-24 07:02:32 UTC
+++ common.gypi
@@ -563,11 +563,11 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris aix os400 openharmony"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix os400 cloudabi openharmony"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
