--- src/corelib/io/io.pri.orig	2024-11-08 13:36:08 UTC
+++ src/corelib/io/io.pri
@@ -100,7 +100,7 @@ qtConfig(filesystemwatcher) {
         SOURCES += io/qfilesystemwatcher_inotify.cpp
         HEADERS += io/qfilesystemwatcher_inotify_p.h
     } else {
-        freebsd|darwin|openbsd|netbsd {
+        freebsd|darwin|openbsd|netbsd|dragonfly|midnightbsd {
             SOURCES += io/qfilesystemwatcher_kqueue.cpp
             HEADERS += io/qfilesystemwatcher_kqueue_p.h
         }
