--- tools/build/src/engine/jam.cpp.orig	2020-12-03 05:02:49 UTC
+++ tools/build/src/engine/jam.cpp
@@ -776,7 +776,6 @@ char * executable_path( char const * arg
 #else
 char * executable_path( char const * argv0 )
 {
-    /* If argv0 is an absolute path, assume it is the right absolute path. */
-    return argv0[ 0 ] == '/' ? strdup( argv0 ) : NULL;
+    return strdup("@LOCALBASE@/bin/jam");
 }
 #endif
