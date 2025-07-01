Sunos link complains when -Wl,-soname is applied to an executable
rather than a library.  The test is bad!!  Force test success.

--- autosetup/proj.tcl.orig	Tue Jul  1 15:14:59 2025
+++ autosetup/proj.tcl	Tue Jul  1 15:15:55 2025
@@ -1157,13 +1157,8 @@
 #
 proc proj-check-soname {{libname "libfoo.so.0"}} {
   cc-with {-link 1} {
-    if {[cc-check-flags "-Wl,-soname,${libname}"]} {
-      define LDFLAGS_SONAME_PREFIX "-Wl,-soname,"
-      return 1
-    } else {
-      define LDFLAGS_SONAME_PREFIX ""
-      return 0
-    }
+    define LDFLAGS_SONAME_PREFIX "-Wl,-soname,"
+    return 1
   }
 }
 
