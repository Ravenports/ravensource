--- tools/v8_gypfiles/v8.gyp.orig	2019-04-24 15:47:36 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -2224,6 +2224,7 @@
         ['OS=="linux"', {
             'link_settings': {
               'libraries': [
+		'@RAVRPATH@',
                 '-ldl',
                 '-lrt'
               ],
@@ -2384,7 +2385,7 @@
         ['OS=="openbsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/local/lib -lexecinfo',
+                '-L/usr/local/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '<(V8_ROOT)/src/base/debug/stack_trace_posix.cc',
@@ -2399,7 +2400,7 @@
         ['OS=="netbsd"', {
             'link_settings': {
               'libraries': [
-                '-L/usr/pkg/lib -Wl,-R/usr/pkg/lib -lexecinfo',
+                '-L/usr/pkg/lib @RAVRPATH@ -lexecinfo',
             ]},
             'sources': [
               '<(V8_ROOT)/src/base/debug/stack_trace_posix.cc',
@@ -2414,7 +2415,7 @@
         ['OS=="solaris"', {
             'link_settings': {
               'libraries': [
-                '-lnsl -lrt',
+                '-lnsl -lrt @RAVRPATH@',
             ]},
             'sources': [
               '<(V8_ROOT)/src/base/debug/stack_trace_posix.cc',
