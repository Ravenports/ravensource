--- common.gypi.orig	2026-07-08 00:30:45 UTC
+++ common.gypi
@@ -564,11 +564,11 @@
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
