--- src/corelib/io/io.pri.orig	2019-01-28 17:11:52 UTC
+++ src/corelib/io/io.pri
@@ -98,7 +98,7 @@ qtConfig(filesystemwatcher) {
         SOURCES += io/qfilesystemwatcher_inotify.cpp
         HEADERS += io/qfilesystemwatcher_inotify_p.h
     } else {
-        freebsd|darwin|openbsd|netbsd {
+        freebsd|darwin|openbsd|netbsd|dragonfly {
             SOURCES += io/qfilesystemwatcher_kqueue.cpp
             HEADERS += io/qfilesystemwatcher_kqueue_p.h
         }
