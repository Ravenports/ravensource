--- deps/v8/gypfiles/v8.gyp.orig	2019-02-14 21:22:43 UTC
+++ deps/v8/gypfiles/v8.gyp
@@ -2027,6 +2027,7 @@
         ['OS=="linux"', {
             'link_settings': {
               'libraries': [
+		'@RAVRPATH@',
                 '-ldl',
                 '-lrt'
               ],
@@ -2203,7 +2204,7 @@
         ['OS=="freebsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/local/lib -lexecinfo',
+                '-L/usr/local/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2233,7 +2234,7 @@
         ['OS=="netbsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/pkg/lib -Wl,-R/usr/pkg/lib -lexecinfo',
+                '-L/usr/pkg/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2248,7 +2249,7 @@
         ['OS=="solaris"', {
             'link_settings': {
               'libraries': [
-                '-lnsl -lrt',
+                '-lnsl -lrt @RAVRPATH@',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
