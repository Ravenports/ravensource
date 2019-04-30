--- tools/v8_gypfiles/broken/standalone.gypi.orig	2019-04-29 12:57:55 UTC
+++ tools/v8_gypfiles/broken/standalone.gypi
@@ -53,6 +53,7 @@
           'variables': {
             'conditions': [
               ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or \
+                 OS=="dragonfly" or \
                  OS=="netbsd" or OS=="mac" or OS=="qnx" or OS=="aix"', {
                 # This handles the Unix platforms we generally deal with.
                 # Anything else gets passed through, which probably won't work
@@ -743,6 +744,7 @@
       },  # target_defaults
     }],  # OS=="mac"
     ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" \
+       or OS=="dragonfly" \
        or OS=="netbsd" or OS=="aix"', {
       'target_defaults': {
         'cflags': [
