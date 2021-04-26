--- tools/build/src/engine/jam.cpp.orig	2021-04-13 16:23:21 UTC
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
