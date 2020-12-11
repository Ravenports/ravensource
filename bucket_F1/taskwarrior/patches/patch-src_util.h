--- src/util.h.orig	2020-11-30 06:30:26 UTC
+++ src/util.h
@@ -35,17 +35,14 @@
 #if defined(FREEBSD) || defined(OPENBSD)
 #include <uuid.h>
 #else
-#include <uuid/uuid.h>
+#include <ossp/uuid++.hh>
 #endif
 #include <Table.h>
 
 // util.cpp
 int confirm4 (const std::string&);
 
-#ifndef HAVE_UUID_UNPARSE_LOWER
-void uuid_unparse_lower (uuid_t uu, char *out);
-#endif
-const std::string uuid ();
+const std::string make_uuid ();
 
 const std::string indentProject (
   const std::string&,
