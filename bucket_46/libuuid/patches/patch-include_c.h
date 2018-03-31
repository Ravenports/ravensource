Add NAME_MAX compat.

--- include/c.h.orig	2018-02-09 12:22:55 UTC
+++ include/c.h
@@ -29,6 +29,10 @@
 # define LOGIN_NAME_MAX 256
 #endif
 
+#ifndef NAME_MAX
+# define NAME_MAX PATH_MAX
+#endif
+
 /*
  * Compiler-specific stuff
  */
