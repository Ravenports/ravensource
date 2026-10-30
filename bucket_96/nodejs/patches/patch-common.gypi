--- common.gypi.orig	2026-10-14 07:50:39 UTC
+++ common.gypi
@@ -588,11 +588,11 @@
           'NOMINMAX',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix os400 openharmony zos"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris aix os400 openharmony zos"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi openharmony zos"', {
+      [ 'OS in "linux freebsd openbsd netbsd solaris android aix os400 cloudabi openharmony zos"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
           '-fno-rtti',
