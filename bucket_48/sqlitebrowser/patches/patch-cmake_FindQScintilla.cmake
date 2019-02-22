--- cmake/FindQScintilla.cmake.orig	2019-02-18 05:21:21 UTC
+++ cmake/FindQScintilla.cmake
@@ -80,7 +80,7 @@ endif ()
 
 
 find_library ( QSCINTILLA_LIBRARY
-  NAMES qscintilla qscintilla2 libqscintilla2
+  NAMES qscintilla qscintilla2 qscintilla2_qt5 libqscintilla2
   HINTS ${QT_LIBRARY_DIR}
 )
 
