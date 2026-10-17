--- common.gypi.orig	2026-10-15 22:04:09.936655000 +0200
+++ common.gypi	2026-10-15 22:05:12.414153000 +0200
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
