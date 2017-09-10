--- src/util.h.orig	2016-02-24 22:18:11 UTC
+++ src/util.h
@@ -35,7 +35,7 @@
 #if defined(FREEBSD) || defined(OPENBSD)
 #include <uuid.h>
 #else
-#include <uuid/uuid.h>
+#include <ossp/uuid++.hh>
 #endif
 #include <Task.h>
 
@@ -45,10 +45,7 @@ int confirm4 (const std::string&);
 std::string formatBytes (size_t);
 int autoComplete (const std::string&, const std::vector<std::string>&, std::vector<std::string>&, int minimum = 1);
 
-#ifndef HAVE_UUID_UNPARSE_LOWER
-void uuid_unparse_lower (uuid_t uu, char *out);
-#endif
-const std::string uuid ();
+const std::string make_uuid ();
 
 int execute (const std::string&, const std::vector <std::string>&, const std::string&, std::string&);
 
