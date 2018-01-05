--- cmake/FindQScintilla.cmake.orig	2017-09-20 13:59:51 UTC
+++ cmake/FindQScintilla.cmake
@@ -80,7 +80,7 @@ endif ()
 
 
 find_library ( QSCINTILLA_LIBRARY
-  NAMES qscintilla qscintilla2 libqscintilla2
+  NAMES qscintilla qscintilla2 qscintilla2_qt5 libqscintilla2
   HINTS ${QT_LIBRARY_DIR}
 )
 
