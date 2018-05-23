$NetBSD: patch-src_corelib_io_io.pri,v 1.4 2015/10/26 19:03:59 adam Exp $

* Add DragonFly support
* Patch sent and merged upstream:
  http://codereview.qt-project.org/#/c/111741/
* fix linux test.

--- src/corelib/io/io.pri.orig	2018-05-14 04:46:28 UTC
+++ src/corelib/io/io.pri
@@ -174,13 +174,13 @@ win32 {
                 io/qstorageinfo_unix.cpp
         }
 
-        linux|if(qnx:qtConfig(inotify)) {
+        linux*|if(qnx:qtConfig(inotify)) {
             SOURCES += io/qfilesystemwatcher_inotify.cpp
             HEADERS += io/qfilesystemwatcher_inotify_p.h
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
