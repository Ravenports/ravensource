--- deps/v8/gypfiles/v8.gyp.orig	2018-09-06 20:44:16 UTC
+++ deps/v8/gypfiles/v8.gyp
@@ -2014,6 +2014,7 @@
         ['OS=="linux"', {
             'link_settings': {
               'libraries': [
+		'@RAVRPATH@',
                 '-ldl',
                 '-lrt'
               ],
@@ -2190,7 +2191,7 @@
         ['OS=="freebsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/local/lib -lexecinfo',
+                '-L/usr/local/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2220,7 +2221,7 @@
         ['OS=="netbsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/pkg/lib -Wl,-R/usr/pkg/lib -lexecinfo',
+                '-L/usr/pkg/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
@@ -2235,7 +2236,7 @@
         ['OS=="solaris"', {
             'link_settings': {
               'libraries': [
-                '-lnsl -lrt',
+                '-lnsl -lrt @RAVRPATH@',
             ]},
             'sources': [
               '../src/base/debug/stack_trace_posix.cc',
