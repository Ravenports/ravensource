--- tools/build/src/engine/pathsys.cpp.orig	2025-04-03 11:37:31 UTC
+++ tools/build/src/engine/pathsys.cpp
@@ -451,36 +451,6 @@ char * executable_path( char const * arg
 #else
 char * executable_path( char const * argv0 )
 {
-    char * result = nullptr;
-    /* If argv0 is an absolute path, assume it is the right absolute path. */
-    if (!result && b2::paths::is_rooted(argv0))
-        result = strdup( argv0 );
-    // If argv0 is a relative path, we can compute the absolute one from the
-    // current working dir.
-    if (!result && b2::paths::is_relative(argv0))
-    {
-        auto p = b2::paths::normalize(b2::cwd_str()+"/"+argv0);
-        result = strdup( p.c_str() );
-    }
-    // If it's a bare basename, search the PATH for a match.
-    if (!result)
-    {
-        std::string path_env = getenv( "PATH" );
-        std::string::size_type i = 0;
-        while (i != std::string::npos)
-        {
-            std::string::size_type e = path_env.find_first_of(':', i);
-            std::string p = e == std::string::npos
-                ? path_env.substr(i)
-                : path_env.substr(i, e-i);
-            if (b2::filesys::is_file(p+"/"+argv0))
-            {
-                result = strdup( (p+"/"+argv0).c_str() );
-                break;
-            }
-            i = e == std::string::npos ? e : e+1;
-        }
-    }
-    return result;
+    return strdup("@LOCALBASE@/bin/jam");
 }
 #endif
