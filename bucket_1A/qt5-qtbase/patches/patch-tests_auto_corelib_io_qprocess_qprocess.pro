$NetBSD: patch-tests_auto_corelib_io_qprocess_qprocess.pro,v 1.1 2014/12/30 17:23:46 adam Exp $

* Pass whitespace(s) in filename test cases.

--- tests/auto/corelib/io/qprocess/qprocess.pro.orig	2024-11-08 13:36:08 UTC
+++ tests/auto/corelib/io/qprocess/qprocess.pro
@@ -3,10 +3,7 @@ TEMPLATE = subdirs
 include(qprocess.pri)
 SUBDIRS  = $$SUBPROGRAMS
 # Add special cases
-SUBDIRS += testProcessSpacesArgs/nospace.pro \
-           testProcessSpacesArgs/onespace.pro \
-           testProcessSpacesArgs/twospaces.pro \
-           testSpaceInName
+SUBDIRS += testProcessSpacesArgs/nospace.pro
 
 win32 {
     SUBDIRS += \
