Add NAME_MAX compat.

--- include/c.h.orig	2025-09-22 10:12:04 UTC
+++ include/c.h
@@ -39,6 +39,10 @@
 
 #define BIT(n)                 (1 << (n))
 
+#ifndef NAME_MAX
+# define NAME_MAX PATH_MAX
+#endif
+
 /*
  * __GNUC_PREREQ is deprecated in favour of __has_attribute() and
  * __has_feature(). The __has macros are supported by clang and gcc>=5.
