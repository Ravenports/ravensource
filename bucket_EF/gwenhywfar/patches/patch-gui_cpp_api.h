--- gui/cpp/api.h.orig	2023-07-27 22:01:05 UTC
+++ gui/cpp/api.h
@@ -12,7 +12,7 @@
 
 #include <gwenhywfar/types.h>
 
-#if (defined __GNUC__ && (! defined (__sun)) && (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))) || defined _MSC_VER
+#if (defined __GNUC__ &&                        (__GNUC__ >= 4 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))) || defined _MSC_VER
 # ifdef BUILDING_CPP_GUI
 /* building Cpp */
 #  if GWENHYWFAR_SYS_IS_WINDOWS
