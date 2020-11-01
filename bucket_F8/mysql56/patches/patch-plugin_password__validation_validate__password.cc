--- plugin/password_validation/validate_password.cc.orig	2020-09-23 12:30:17 UTC
+++ plugin/password_validation/validate_password.cc
@@ -23,6 +23,8 @@
 #include <my_sys.h>
 #include <string>
 #include <mysql/plugin_validate_password.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <ios>       // std::streamoff
 #include <iostream>
