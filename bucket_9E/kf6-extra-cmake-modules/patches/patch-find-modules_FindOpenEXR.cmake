--- find-modules/FindOpenEXR.cmake.orig	2026-01-02 17:40:05 UTC
+++ find-modules/FindOpenEXR.cmake
@@ -45,6 +45,13 @@ pkg_check_modules(PC_OpenEXR QUIET OpenE
 
 set(OpenEXR_DEFINITIONS ${PC_OpenEXR_CFLAGS_OTHER})
 
+find_path(Imath_INCLUDE_DIR ImathMath.h
+   PATHS
+   ${PC_Imath_INCLUDEDIR}
+   ${PC_Imath_INCLUDE_DIRS}
+   PATH_SUFFIXES Imath
+)
+
 find_path(OpenEXR_INCLUDE_DIR ImfRgbaFile.h
    PATHS
    ${PC_OpenEXR_INCLUDEDIR}
@@ -53,7 +60,7 @@ find_path(OpenEXR_INCLUDE_DIR ImfRgbaFil
 )
 
 # Required libraries for OpenEXR
-find_library(OpenEXR_HALF_LIBRARY NAMES Half
+find_library(OpenEXR_HALF_LIBRARY NAMES Imath
    PATHS
    ${PC_OpenEXR_LIBDIR}
    ${PC_OpenEXR_LIBRARY_DIRS}
@@ -74,7 +81,7 @@ find_library(OpenEXR_ILMTHREAD_LIBRARY N
    ${PC_OpenEXR_LIBRARY_DIRS}
 )
 # This is the actual OpenEXR library
-find_library(OpenEXR_ILMIMF_LIBRARY NAMES IlmImf
+find_library(OpenEXR_ILMIMF_LIBRARY NAMES OpenEXR
    PATHS
    ${PC_OpenEXR_LIBDIR}
    ${PC_OpenEXR_LIBRARY_DIRS}
@@ -110,9 +117,10 @@ find_package_handle_standard_args(OpenEX
       OpenEXR_IMATH_LIBRARY
       OpenEXR_ILMTHREAD_LIBRARY
       OpenEXR_INCLUDE_DIR
+      Imath_INCLUDE_DIR
    VERSION_VAR OpenEXR_VERSION_STRING)
 
-set(OpenEXR_INCLUDE_DIRS ${OpenEXR_INCLUDE_DIR})
+set(OpenEXR_INCLUDE_DIRS ${Imath_INCLUDE_DIR} ${OpenEXR_INCLUDE_DIR})
 
 include(FeatureSummary)
 set_package_properties(OpenEXR PROPERTIES
