--- m4/fltk.m4.orig	2014-06-21 23:24:06.000000000 +0200
+++ m4/fltk.m4	2025-10-14 21:16:05.304445000 +0200
@@ -37,7 +37,7 @@
 			AC_MSG_RESULT(yes)
 			;;
 			dnl check for FLTK 1.3.x branch
-			["1.3."[0123456789]])
+			[1.[3456].*])
 			HAVE_FL_TREE=1
 			AC_MSG_RESULT(yes)
 			;;
