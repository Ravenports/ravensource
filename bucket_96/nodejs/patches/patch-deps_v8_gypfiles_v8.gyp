--- deps/v8/gypfiles/v8.gyp.orig	2019-01-30 20:43:13 UTC
+++ deps/v8/gypfiles/v8.gyp
@@ -2025,6 +2025,7 @@
         ['OS=="linux"', {
             'link_settings': {
               'libraries': [
+		'@RAVRPATH@',
                 '-ldl',
                 '-lrt'
               ],
@@ -2201,7 +2202,7 @@
         ['OS=="freebsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/local/lib -lexecinfo',
+                '-L/usr/local/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2231,7 +2232,7 @@
         ['OS=="netbsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/pkg/lib -Wl,-R/usr/pkg/lib -lexecinfo',
+                '-L/usr/pkg/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2246,7 +2247,7 @@
         ['OS=="solaris"', {
             'link_settings': {
               'libraries': [
-                '-lnsl -lrt',
+                '-lnsl -lrt @RAVRPATH@',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
