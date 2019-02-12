--- deps/v8/gypfiles/standalone.gypi.orig	2019-02-07 19:20:04 UTC
+++ deps/v8/gypfiles/standalone.gypi
@@ -53,6 +53,7 @@
           'variables': {
             'conditions': [
               ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or \
+                 OS=="dragonfly" or \
                  OS=="netbsd" or OS=="mac" or OS=="qnx" or OS=="aix"', {
                 # This handles the Unix platforms we generally deal with.
                 # Anything else gets passed through, which probably won't work
@@ -747,6 +748,7 @@
       },  # target_defaults
     }],  # OS=="mac"
     ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" \
+       or OS=="dragonfly" \
        or OS=="netbsd" or OS=="aix"', {
       'target_defaults': {
         'cflags': [
