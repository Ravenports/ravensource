Sunos link complains when -Wl,-soname is applied to an executable
rather than a library.  The test is bad!!  Force test success.

--- autosetup/proj.tcl.orig	2025-11-28 17:50:50 UTC
+++ autosetup/proj.tcl
@@ -1196,17 +1196,8 @@ proc proj-check-rpath {} {
 #
 proc proj-check-soname {{libname "libfoo.so.0"}} {
   cc-with {-link 1} {
-    if {[cc-check-flags "-Wl,-soname,${libname}"]} {
-      define LDFLAGS_SONAME_PREFIX "-Wl,-soname,"
-      return 1
-    } elseif {[cc-check-flags "-Wl,+h,${libname}"]} {
-      # HP-UX: https://sqlite.org/forum/forumpost/d80ecdaddd
-      define LDFLAGS_SONAME_PREFIX "-Wl,+h,"
-      return 1
-    } else {
-      define LDFLAGS_SONAME_PREFIX ""
-      return 0
-    }
+    define LDFLAGS_SONAME_PREFIX "-Wl,-soname,"
+    return 1
   }
 }
 
