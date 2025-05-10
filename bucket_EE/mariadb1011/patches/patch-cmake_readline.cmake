--- cmake/readline.cmake.orig	2025-04-28 13:44:13 UTC
+++ cmake/readline.cmake
@@ -52,40 +52,17 @@ MACRO (MYSQL_CHECK_MULTIBYTE)
 ENDMACRO()
 
 MACRO (FIND_CURSES)
+ SET(CURSES_NEED_NCURSES True)
  FIND_PACKAGE(Curses REQUIRED)
  MARK_AS_ADVANCED(CURSES_CURSES_H_PATH CURSES_FORM_LIBRARY CURSES_HAVE_CURSES_H)
  IF(NOT CURSES_FOUND)
    SET(ERRORMSG "Curses library not found. Please install appropriate package,
     remove CMakeCache.txt and rerun cmake.")
-   IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
-    SET(ERRORMSG ${ERRORMSG} 
-    "On Debian/Ubuntu, package name is libncurses5-dev, on Redhat and derivatives " 
-    "it is ncurses-devel.")
-   ENDIF()
    MESSAGE(FATAL_ERROR ${ERRORMSG})
  ENDIF()
 
- IF(CURSES_HAVE_CURSES_H)
-   SET(HAVE_CURSES_H 1 CACHE INTERNAL "")
- ENDIF()
- IF(CMAKE_SYSTEM_NAME MATCHES "HP")
-   # CMake uses full path to library /lib/libcurses.sl 
-   # On Itanium, it results into architecture mismatch+
-   # the library is for  PA-RISC
-   SET(CURSES_LIBRARY "curses" CACHE INTERNAL "" FORCE)
- ENDIF()
+ SET(HAVE_CURSES_H 1 CACHE INTERNAL "")
 
- IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
-   # -Wl,--as-needed breaks linking with -lcurses, e.g on Fedora 
-   # Lower-level libcurses calls are exposed by libtinfo
-   CHECK_LIBRARY_EXISTS(${CURSES_LIBRARY} tputs "" HAVE_TPUTS_IN_CURSES)
-   IF(NOT HAVE_TPUTS_IN_CURSES)
-     CHECK_LIBRARY_EXISTS(tinfo tputs "" HAVE_TPUTS_IN_TINFO)
-     IF(HAVE_TPUTS_IN_TINFO)
-       SET(CURSES_LIBRARY tinfo)
-     ENDIF()
-   ENDIF() 
- ENDIF()
  CHECK_LIBRARY_EXISTS(${CURSES_LIBRARY} setupterm "" HAVE_SETUPTERM)
  CHECK_LIBRARY_EXISTS(${CURSES_LIBRARY} vidattr "" HAVE_VIDATTR)
 ENDMACRO()
@@ -223,6 +200,8 @@ MACRO (MYSQL_CHECK_READLINE)
     SET(CMAKE_REQUIRED_LIBRARIES)
     SET(CMAKE_REQUIRED_INCLUDES)
   ENDIF(NOT WIN32)
+  SET(CMAKE_REQUIRED_INCLUDES ${CURSES_INCLUDE_DIR}/ncurses)
   CHECK_INCLUDE_FILES ("curses.h;term.h" HAVE_TERM_H)
+  SET(CMAKE_REQUIRED_INCLUDES)
 ENDMACRO()
 
